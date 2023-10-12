from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'battery_state_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='gcy',
    maintainer_email='gcy@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = battery_state_py.publisher_member_function:main',
            'listener = battery_state_py.subscriber_member_function:main',
            # launch文件里的executable名称就是左边的名字
        ],
    },
)
