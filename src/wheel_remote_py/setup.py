from setuptools import find_packages, setup

package_name = 'wheel_remote_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='gcy',
    maintainer_email='gcy15256266892@163.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'wheel_publisher = wheel_remote_py.publish_wheel:main',
            'wheel_receiver = wheel_remote_py.receive_wheel_test:main',
        ],
    },
)
