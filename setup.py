from setuptools import find_packages, setup


setup(
    name="gps",
    version="3.9",
    packages=find_packages(),
    description="GPSD is a service daemon that handles GPSes and other navigation-related sensors reporting over USB, serial, TCP/IP, or UDP connections and presents reports in a well-documented JSON application on port 2749.",
    license="BSD",
    keywords="gsp",
    url='https://savannah.nongnu.org/projects/gpsd/',
)
