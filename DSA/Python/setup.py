from setuptools import find_packages
from setuptools import setup

version = '1.0.1'

# with open('./requirements.txt') as f:
#     requires = f.read().splitlines()
requires = ["tox"]

setup(
    name="DSA",
    version=version,
    description='Data Structure and Algorithm',
    long_description=open('README.md').read(),
    author='Jackie Ma',
    author_email='jackie.ma@tophant.com',
    url='https://github.com/JackieMa000/problems',
    packages=find_packages('src'),
    package_dir={'': 'src'},
    include_package_data=True,
    namespace_packages=['dsa'],
    zip_safe=False,
    install_requires=requires,
)
