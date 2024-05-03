from setuptools import find_packages, setup

package_name = 'gpp_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/model', [
            'model/policy_net_final.pth',
            'model/policy_net_initial.pth'
        ]),
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
            'gpp_client = gpp_pkg.main:main',
            'gpp_service = gpp_pkg.motion_controller_node:main',
        ],
    },
)
