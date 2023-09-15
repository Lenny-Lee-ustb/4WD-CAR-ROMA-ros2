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
        (os.path.join('share', package_name, 'launch'), glob('launch/test_launch.py')),
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
            'talker = py_pubsub.publisher_member_function:main',
            'listener = py_pubsub.subscriber_member_function:main',
            # launch文件里的executable名称就是左边的名字
        ],
    },
)
