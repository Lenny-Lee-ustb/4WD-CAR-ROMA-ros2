#! /usr/bin/expect -f
set timeout 1              
spawn setserial /dev/servo low_latency
spawn setserial /dev/sbus low_latency
spawn setserial /dev/imu low_latency
interact
