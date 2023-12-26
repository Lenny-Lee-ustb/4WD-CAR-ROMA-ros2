#include <iostream>
#include <string>
#include <pthread.h>
#include <sched.h>
#include "boost/asio.hpp"

#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;
using namespace boost::asio;

static const size_t BUF_SIZE = 1024;

size_t recv_len;

volatile uint8_t received = 0;

#define CH_COUNT 50
typedef struct Frame
{
  float fdata[CH_COUNT];
  uint8_t tail[4];
} Frame;
Frame rxmsg = {
    .fdata = {0}, 
    .tail = {0x00, 0x00, 0x80, 0x7f}};

void *receive_from_thread(void *data)
{

  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(0, &cpuset); // Set CPU 1

  int rc = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
  if (rc != 0)
  {
    // Handle error
  }

  io_service *ios = static_cast<io_service *>(data);
  ip::udp::socket udp_server(*ios);
  ip::udp::endpoint local_addr(ip::address::from_string("192.168.7.2"), 8888);
  // ip::udp::endpoint local_addr(ip::address::from_string("192.168.10.1"), 7777);
  //  ip::udp::endpoint local_addr(ip::address::from_string("192.168.7.2"), 8888);
  udp_server.open(local_addr.protocol());
  udp_server.bind(local_addr);
  static uint8_t buf[BUF_SIZE] = "";
  ip::udp::endpoint send_point;

 
  while (true)
  {

    recv_len = udp_server.receive_from(buffer(buf, BUF_SIZE), send_point);
    memcpy(&rxmsg, buf, recv_len);

    received = 1;
  }

  return nullptr;
}

int main()
{
  mlockall(MCL_CURRENT | MCL_FUTURE);

  io_service ios;
  pthread_t thread_id;
  pthread_attr_t attr;
  int ret;

  // Initialize the thread attributes
  ret = pthread_attr_init(&attr);
  if (ret)
  {
    cout << "Unable to initialize thread attributes." << endl;
    return 1;
  }

  // Set the thread to be schedulable in real-time policies
  ret = pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
  if (ret)
  {
    cout << "Unable to set thread scheduling policy." << endl;
    return 1;
  }

  // Set the thread priority
  struct sched_param param;
  param.sched_priority = 80;
  ret = pthread_attr_setschedparam(&attr, &param);
  if (ret)
  {
    cout << "Unable to set thread scheduling parameters." << endl;
    return 1;
  }

  // Set the thread to explicitly use the attributes specified
  ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
  if (ret)
  {
    cout << "Unable to set thread scheduling inheritance." << endl;
    return 1;
  }

  // Create the thread
  ret = pthread_create(&thread_id, &attr, receive_from_thread, &ios);
  if (ret)
  {
    cout << "Unable to create thread." << endl;
    return 1;
  }

  while (true)
  {
    if (received)
    {
      received = 0;

      for (size_t i = 0; i < 16; i++)
      {
        printf("ch%d %f, ", i,  rxmsg.fdata[i]);
      }
      printf("\n");
    }
    usleep(1);
  }

  // Wait for the thread to finish
  pthread_join(thread_id, nullptr);

  // Clean up the thread attributes
  pthread_attr_destroy(&attr);

  return 0;
}
