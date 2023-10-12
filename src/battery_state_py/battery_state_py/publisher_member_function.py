# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
import serial

from sensor_msgs.msg import BatteryState

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('battery_publisher')
        # self.publisher_ = self.create_publisher(String, 'topic_test', 10)
        self.publisher_ = self.create_publisher(BatteryState, 'battery_state', 10)
        timer_period = 0.8  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0


    def timer_callback(self):
        # msg = String()
        battery = batteryState()
        msg = BatteryState()
        # msg.data = 'Hello World: %d' % self.i
        msg.voltage = battery.voltage
        msg.current = battery.current
        # msg.charge = battery.charge
        msg.capacity = battery.capacity
        msg.design_capacity = battery.design_capacity
        msg.percentage = battery.percentage
        msg.temperature = battery.temperature
        # msg.power_supply_status = battery.power_supply_status
        msg.power_supply_health = battery.power_supply_health
        msg.power_supply_technology = battery.power_supply_technology
        msg.cell_voltage = battery.cell_voltage

        self.publisher_.publish(msg)
        # self.get_logger().info('Send: \n Battery voltage: %.2f V; Battery temperature: %.2f C; Battery percentage: %d %%' % (msg.voltage, msg.temperature, msg.percentage))
        self.i += 1

def hexShow(argv):        #十六进制显示 方法1
    try:
        result = ''  
        hLen = len(argv)  
        for i in range(hLen):  
            hvol = argv[i]
            hhex = '%02x'%hvol  
            result += hhex+' '  
            # print('hexShow:',result)
    except:
        pass
    return result

def bytes2int(inputdata:list, num:int):
    data_high = inputdata[num]
    data_low = inputdata[num + 1]
    data_int = data_high * 256 + data_low
    return data_int

def batteryHealth(temperature:float):
    if temperature < 0:
        return 6
    elif temperature <= 40 and temperature >= 0:
        return 1
    elif temperature >= 40:
        return 2
    else:
        return

class Battery():
    def __init__(self, port_name:str, baudrate:int):
        self.port_name = port_name
        self.baudrate = baudrate
    
    def getState(self):
        ser = serial.Serial(self.port_name, self.baudrate, timeout=0.1)
        # print('连接成功')
        # 发送请求数据
        state_req = 'DD A5 03 00 FF FD 77'
        request_data = bytes.fromhex(state_req)
        ser.write(request_data)
        # print('发送成功')
        response_data = ser.read(40)  # 根据您的数据长度调整读取的字节数

        # 解析返回数据
        if response_data:   # 如果读取结果非空，则输出
            # data= str(binascii.b2a_hex(response_data))[2:-1] #十六进制显示方法2
            data3 = hexShow(response_data)
            out_data = data3.split()
            # print(out_data, type(out_data), len(out_data))

            # 解析返回数据
            if out_data[2] == '00':
                # print('ok')
                voltage = bytes2int(response_data, 4) / 100
                # print('Current voltage: %.2f V' % voltage)
                current = bytes2int(response_data, 6) / 100
                # print('Current current: %.2f A' % current)
                capacity = bytes2int(response_data, 8) / 100
                # print('Current capacity: %.2f Ah' % capacity)
                self.capacity = float(capacity)
                design_capacity = bytes2int(response_data, 10) / 100
                # print('Design capacity: %.2f Ah' % design_capacity)
                temp_sensor = response_data[26]
                temperature1 = (bytes2int(response_data, 27) -2731) / 10
                temperature2 = (bytes2int(response_data, 29) -2731) / 10
                temperature = max(temperature1, temperature2)
                # print('%d temp sensors detected. \n \
                #     Temperature1: %.2f C, Temperature2: %.2f C, Max temperature: %.2f C' \
                #     % (temp_sensor, temperature1, temperature2, temperature))
                percentage = response_data[23]
                # print('Battery percentage: %.2f %%' % percentage)
                cellsNum = response_data[25]
                # print('Battery cells: %d' % cellsNum)

                self.voltage = float(voltage)
                self.current = float(current)
                self.capacity = float(capacity)
                self.design_capacity = float(design_capacity)
                self.temperature = float(temperature)
                self.percentage = float(percentage)
                self.cellsNum = int(cellsNum)
                self.power_supply_health = batteryHealth(self.temperature)
                self.power_supply_technology = 2
            ser.close()
            return 1
        # 关闭串口连接
        else:
            ser.close()
            return 0
            
        
    
    def getVoltage(self):
        ser = serial.Serial(self.port_name, self.baudrate, timeout=0.1)
        # print('连接成功')
        # 发送请求数据
        volt_req = 'DD A5 04 00 FF FC 77'
        request_data = bytes.fromhex(volt_req)
        ser.write(request_data)
        # time.sleep(0.1)
        # print('发送成功')
        response_data = ser.read(40)  # 根据您的数据长度调整读取的字节数
        if response_data:   # 如果读取结果非空，则输出
            # data= str(binascii.b2a_hex(response_data))[2:-1] #十六进制显示方法2
            data3 = hexShow(response_data)
            out_data = data3.split()
            # print(out_data, type(out_data), len(out_data))

            # 解析返回数据
            if out_data[2] == '00':
                # print('ok')
                num_batteries = response_data[3] // 2
                # print(num_batteries)
                voltage_values = []

                for i in range(num_batteries):
                    voltage_high = response_data[4 + i * 2]
                    voltage_low = response_data[5 + i * 2]
                    voltage_value = voltage_high * 256 + voltage_low
                    voltage_decimal = voltage_value / 1000
                    voltage_values.append(voltage_decimal)

                # print("电池单体电压值列表:", voltage_values)
                self.cell_voltage = voltage_values
                return 1
            ser.close()
        else:
            # print("返回数据格式不正确或状态异常")

            # 关闭串口连接
            ser.close()
            return 0

def batteryState(args = None):
    battery = Battery('/dev/battery', 9600)
    while True:
        a = battery.getState()
        b = battery.getVoltage()
        # print(a * b)
        if a*b == 1:
            # print(dir(battery))
            break
    return battery

def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()