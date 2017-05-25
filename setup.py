from setuptools import setup, find_packages

setup(
    name='Flask',
    version='1.0',
    packages=find_packages(),
    include_package_data=True,
    zip_safe=False,
    install_requires=['Flask']
)