from setuptools import find_packages, setup

package_name = 'global_path_test_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/multi_robot_launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='weng',
    maintainer_email='weng@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'navigation = global_path_test_pkg.navigation:main',
            'robot_navigator = global_path_test_pkg.robot_navigator:main',
            'robot_controller = global_path_test_pkg.robot_controller:main',
        ],
    },
)
