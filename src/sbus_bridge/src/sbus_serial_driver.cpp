/*
 * Copyright 2018 Jens Willy Johannsen <jens@jwrobotics.com>, JW Robotics
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentauart_confign files (the "Software"), to deal
 * in the Software without restricuart_confign, including without limitauart_confign the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following condiuart_configns:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial poruart_configns of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACuart_configN OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECuart_configN WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * SBUS driver
 * Based on code from:
 *	https://github.com/uzh-rpg/rpg_quadrotor_control
 */

#include <sbus_bridge/sbus_serial_driver.h>

#include <asm/ioctls.h>
#include <asm/termbits.h>
#include <deque>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/poll.h>
#include <sys/ioctl.h>
#include <cstdio>
#include <unistd.h>
#include <stdexcept>
#include <vector>
#include <chrono>
#include <iostream>

namespace sbus_serial
{

	SBusSerialPort::SBusSerialPort() : receiver_thread_(), receiver_thread_should_exit_(false), serial_port_fd_(-1)
	{
	}

	SBusSerialPort::SBusSerialPort(const std::string &port, const bool start_receiver_thread) : receiver_thread_(),
																								receiver_thread_should_exit_(false),
																								serial_port_fd_(-1),
																								callback_(nullptr)
	{
		bool success = setUpSBusSerialPort(port, start_receiver_thread);
		if (!success)
			throw std::runtime_error("Unable to open UART port");
	}

	SBusSerialPort::~SBusSerialPort()
	{
		disconnectSerialPort();
	}

	void SBusSerialPort::setCallback(SBusCallback callback)
	{
		callback_ = callback;
	}

	bool SBusSerialPort::setUpSBusSerialPort(const std::string &port,
											 const bool start_receiver_thread)
	{
		if (!connectSerialPort(port))
		{
			return false;
		}

		if (start_receiver_thread)
		{
			if (!startReceiverThread())
			{
				return false;
			}
		}

		return true;
	}

	bool SBusSerialPort::connectSerialPort(const std::string &port)
	{
		// Open serial port
		// O_RDWR - Read and write
		// O_NOCTTY - Ignore special chars like CTRL-C
		serial_port_fd_ = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
		printf("Connect to serial port\n");

		if (serial_port_fd_ == -1)
		{
			printf("Could not open serial port: '%s'\n", port.c_str());
			return false;
		}

		if (!configureSerialPortForSBus())
		{
			::close(serial_port_fd_);
			printf("Could not set necessary configurauart_confign of serial port\n");
			return false;
		}

		return true;
	}

	void SBusSerialPort::disconnectSerialPort()
	{
		stopReceiverThread();

		::close(serial_port_fd_);
	}

	bool SBusSerialPort::startReceiverThread()
	{
		// Start watchdog thread
		try
		{
			receiver_thread_ = std::thread(&SBusSerialPort::serialPortReceiveThread,
										   this);
		}
		catch (...)
		{
			printf("Could not successfully start SBUS receiver thread.\n");
			return false;
		}

		return true;
	}

	bool SBusSerialPort::stopReceiverThread()
	{
		if (!receiver_thread_.joinable())
		{
			return true;
		}

		receiver_thread_should_exit_ = true;

		// Wait for receiver thread to finish
		receiver_thread_.join();

		return true;
	}

	// bool SBusSerialPort::configureSerialPortForSBus() const
	// {
	// 	// clear config
	// 	fcntl(serial_port_fd_, F_SETFL, 0);
	// 	// read non blocking
	// 	fcntl(serial_port_fd_, F_SETFL, O_NONBLOCK);

	// 	struct termios2 uart_config;
	// 	/* Fill the struct for the new configurauart_confign */
	// 	ioctl(serial_port_fd_, TCGETS2, &uart_config);

	// 	// 设置波特率为115200
	// 	uart_config.c_cflag &= ~CBAUD; // 清除波特率标志
	// 	uart_config.c_cflag |= BOTHER; // 使用非标准波特率
	// 	uart_config.c_ispeed = 115200; // 输入波特率
	// 	uart_config.c_ospeed = 115200; // 输出波特率
	// 	// 设置数据位为8位
	// 	uart_config.c_cflag |= CLOCAL | CREAD;
	// 	uart_config.c_cflag &= ~CSIZE;
	// 	uart_config.c_cflag |= CS8;
	// 	// 设置停止位为1位
	// 	uart_config.c_cflag &= ~CSTOPB;
	// 	// 禁用奇偶校验
	// 	uart_config.c_cflag &= ~PARENB;
	// 	uart_config.c_iflag &= ~INPCK;
	// 	// disable hard flow
	// 	uart_config.c_cflag &= ~CRTSCTS;

	// 	if (ioctl(serial_port_fd_, TCSETS2, &uart_config) < 0)
	// 	{
	// 		printf("[Could not set configurauart_confign of serial port]\n");
	// 		return false;
	// 	}

	// 	return true;
	// }
	bool SBusSerialPort::configureSerialPortForSBus() const
	{
		// clear config
		fcntl( serial_port_fd_, F_SETFL, 0 );
		// read non blocking
		fcntl( serial_port_fd_, F_SETFL, FNDELAY );

		struct termios2 uart_config;
		/* Fill the struct for the new configuration */
		ioctl( serial_port_fd_, TCGETS2, &uart_config );

		// Output flags - Turn off output processing
		// no CR to NL translation, no NL to CR-NL translation,
		// no NL to CR translation, no column 0 CR suppression,
		// no Ctrl-D suppression, no fill characters, no case mapping,
		// no local output processing
		//
		uart_config.c_oflag &= ~(OCRNL | ONLCR | ONLRET | ONOCR | OFILL | OPOST);

		// Input flags - Turn off input processing
		// convert break to null byte, no CR to NL translation,
		// no NL to CR translation, don't mark parity errors or breaks
		// no input parity check, don't strip high bit off,
		// no XON/XOFF software flow control
		//
		uart_config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK
					 | ISTRIP | IXON);

		//
		// No line processing:
		// echo off
		// echo newline off
		// canonical mode off,
		// extended input processing off
		// signal chars off
		//
		uart_config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

		// Turn off character processing
		// Turn off odd parity
		uart_config.c_cflag &= ~(CSIZE | PARODD | CBAUD);

		// Enable parity generation on output and parity checking for input.
		// uart_config.c_cflag |= PARENB;
		// Set two stop bits, rather than one.
		// uart_config.c_cflag |= CSTOPB;
		// No output processing, force 8 bit input
		uart_config.c_cflag |= CS8;
		// Enable a non standard baud rate
		uart_config.c_cflag |= BOTHER;

		// Set custom baud rate of 100'000 bits/s necessary for sbus
		// const speed_t spd = 100000;
		const speed_t spd = 115200;

		uart_config.c_ispeed = spd;
		uart_config.c_ospeed = spd;

		if( ioctl( serial_port_fd_, TCSETS2, &uart_config ) < 0 )
		{
			printf( "[Could not set configuration of serial port\n" );
			return false;
		}

		return true;
	}


	void SBusSerialPort::serialPortReceiveThread()
	{
		std::deque<uint8_t> bytes_buf;
		uint8_t temp[2048];
		ssize_t size = read(serial_port_fd_, temp, sizeof(temp));
		printf("fist buf:%ld\n",size);

		while (!receiver_thread_should_exit_)
		{
			uint8_t read_buf[4 * kSbusFrameLength_];
			bool valid_sbus_message_received = false;
			uint8_t sbus_msg_bytes[kSbusFrameLength_];
			const ssize_t nread = read(serial_port_fd_, read_buf, sizeof(read_buf));
			
			// printf("normal buf:%ld\n",nread);

			// printf("Size[%ld]: ", nread);
			// for (ssize_t i = 0; i < nread; i++)
			// {
			// 	printf("%2x,",read_buf[i]);
			// }
			// printf("\n");


			for (ssize_t i = 0; i < nread; i++)
			{
				bytes_buf.emplace_back(read_buf[i]);
			}

			// If not, pop front elements until we have a valid header byte
			while (!bytes_buf.empty() && bytes_buf.front() != kSbusHeaderByte_)
			{
				bytes_buf.pop_front();
			}

			while (bytes_buf.size() >= kSbusFrameLength_)
			{
				if (bytes_buf.front() == kSbusHeaderByte_ && !(bytes_buf[kSbusFrameLength_ - 2] & 0xF0))
				{
					for (uint8_t i = 0; i < kSbusFrameLength_; i++)
					{
						sbus_msg_bytes[i] = bytes_buf.front();
						bytes_buf.pop_front();
					}
					valid_sbus_message_received = true;
				}
				else
				{
					// If it is not a valid SBUS message but has a correct header byte
					// we need to pop it to prevent staying in this loop forever
					bytes_buf.pop_front();
					printf("SBUS message framing not in sync here\n");
				}

				if (valid_sbus_message_received)
				{
					SBusMsg received_sbus_msg;
					parseSbusMessage(sbus_msg_bytes, received_sbus_msg);
					if (callback_ != nullptr)
						callback_(received_sbus_msg);
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		return;
	}

	void SBusSerialPort::parseSbusMessage(
		uint8_t sbus_msg_bytes[kSbusFrameLength_], SBusMsg& received_sbus_msg) 
	{
		// Decode the 16 regular channels
		for (uint8_t i = 0; i < 16; i++)
		{
			received_sbus_msg.channels[i] = ((uint16_t)sbus_msg_bytes[2 * i + 1] << 8) | ((uint16_t)sbus_msg_bytes[2 * i + 2]);
		}
		if (sbus_msg_bytes[33] & (1 << 2))
		{
			received_sbus_msg.frame_lost = true;
		}
		else
		{
			received_sbus_msg.frame_lost = false;
		}

		if (sbus_msg_bytes[33] & (1 << 3))
		{
			received_sbus_msg.failsafe = true;
		}
		else
		{
			received_sbus_msg.failsafe = false;
		}
	}
} // namespace sbus_serial