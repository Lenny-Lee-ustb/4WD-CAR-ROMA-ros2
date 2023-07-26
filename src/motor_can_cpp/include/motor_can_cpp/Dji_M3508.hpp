#include <unistd.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>

#include <linux/can.h>
#include <linux/can/raw.h>
#include "motor_can_cpp/PID_controller.h"

class Motor_M3508
{
private:
	double a_1, b_0, b_1;
	double preTorque_;
	double getSignNum(double x, double threshold);
	PIDController motorPID;

public:
	Motor_M3508();
	~Motor_M3508();

	int16_t curRx, velRx, angleRx, curTx;
	int8_t thermalRx; // Monitor thermal

	double K;
	double temperature;																				  // C
	double tor, torLast, torFiltered, torFiltered_Last, torqueDes, torqueConst, torqueMax, torqueMin; // tor = K*cur
	double speed, speedLast, speedFiltered, speedFiltered_Last, speedDes, speedErr;					  // m/s

	int16_t MotorTune();
	bool MotorSetup(double Kp, double Ki, double Kd, double IBound, double dt, double preTorque, double filter_a1, double filter_b0, double filter_b1, double K_motor, double maxTorque, double minTorque);
	double LowPassFilter(double yLast, double x, double xLast);
	void SendZero(int s);
};

Motor_M3508::Motor_M3508() : speedLast(0), speedFiltered_Last(0){}
Motor_M3508::~Motor_M3508() {}

bool Motor_M3508::MotorSetup(double Kp,
							 double Ki,
							 double Kd,
							 double IBound,
							 double dt,
							 double preTorque,
							 double filter_a1,
							 double filter_b0,
							 double filter_b1,
							 double K_motor,
							 double maxTorque,
							 double minTorque)
{
	motorPID.setPID(Kp, Ki, Kd, IBound, dt);
	preTorque_ = preTorque;
	a_1 = filter_a1;
	b_0 = filter_b0;
	b_1 = filter_b1;
	K = K_motor;
	torqueMax = maxTorque;
	torqueMin = minTorque;
	return 1;
}

int16_t Motor_M3508::MotorTune()
{
	// This method is borrowed from MIT Cheetah, which is used in Tmotor AK series.
	double T_ref;
	int16_t iqref;
	if (speedDes != 0 && torqueDes == 0)
	{
		T_ref = motorPID.calculateOutput(speedDes, speed);
		T_ref = T_ref + getSignNum(T_ref, 0.2) * preTorque_;
	}
	else if (speedDes == 0 && torqueDes != 0)
	{
		T_ref = torqueDes;
	}
	else{
		T_ref = 0;
	}

	T_ref = std::min(std::max(T_ref, torqueMin), torqueMax);
	iqref = (int16_t)round(T_ref / K * (16384.0 / 20.0));
	iqref = std::min(std::max(iqref, (int16_t)-16384), (int16_t)16384);
	return iqref;
}

double Motor_M3508::LowPassFilter(double yLast, double x, double xLast)
{
	// low-pass filter for motor's sensor, ylast is the last estimate value, x is observed value
	double f;
	// y_{n} = a_1 * y_{n-1} + b_0 * x_{n} + b_1 * x_{n-1}
	f = a_1 * yLast + b_0 * x + b_1 * xLast;
	return f;
}

double Motor_M3508::getSignNum(double x, double threshold)
{
	if (x > threshold)
		return 1;
	if (x < -threshold)
		return -1;
	return 0;
}

void Motor_M3508::SendZero(int s)
{
	int nbytes;
	can_frame frame;
	frame.can_id = 0x200;
	frame.can_dlc = 8;
	for (int i = 0; i < 4; i++)
	{
		frame.data[2 * i] = 0;
		frame.data[2 * i + 1] = 0;
	}
	nbytes = write(s, &frame, sizeof(struct can_frame));

	if (nbytes == -1)
	{
		printf("send error\n");
	}
}