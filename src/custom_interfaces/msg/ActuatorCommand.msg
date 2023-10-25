# This contains multi actuators' command.

std_msgs/Header header
int32 drive_mode #0:neutral 1:velocity 2:effort
Actuator[4] actuator_command