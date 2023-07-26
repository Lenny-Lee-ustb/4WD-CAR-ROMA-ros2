#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#endif
#include <unistd.h>
#include <chrono>
#include <thread>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string.h>


#include <linux/can.h>
#include <linux/can/raw.h>

int socketCANInit(std::string canMotorSeries)
{
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr_;
    // CAN bus init
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
    {
        perror("Error while opening socket");
        return -1;
    }
    strcpy(ifr_.ifr_name, canMotorSeries.c_str());
    ioctl(s, SIOCGIFINDEX, &ifr_);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr_.ifr_ifindex;
    printf("%s at index %d\n", ifr_.ifr_name, ifr_.ifr_ifindex);
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Error in socket bind");
        return -2;
    }
    return s;
}

void canSetup(std::string canNumber, std::string passwd)
{
    // 要执行的系统命令
    std::string command ="echo "+ passwd +" | sudo -S ip link set " + canNumber + " up type can bitrate 1000000";

    // 使用 system() 函数来执行命令
    int exitCode = system(command.c_str());

    // 检查命令是否执行成功
    if (exitCode == 0)
    {
        std::cout << "Command executed successfully." << std::endl;
    }
    else
    {
        std::cout << "Command execution failed." << std::endl;
    }
}

void canShutdown(std::string canNumber, std::string passwd)
{
    // 要执行的系统命令
    std::string command = "echo "+ passwd +" | sudo -S ip link set " + canNumber + " down";

    // 使用 system() 函数来执行命令
    int exitCode = system(command.c_str());

    // 检查命令是否执行成功
    if (exitCode == 0)
    {
        std::cout << "Command executed successfully." << std::endl;
    }
    else
    {
        std::cout << "Command execution failed." << std::endl;
    }
}