import os
from setuptools import find_packages, setup


here = os.path.abspath(os.path.dirname(__file__))


about = {}
with open(os.path.join(here, 'gps', '__version__.py'), 'r') as f:
    exec(f.read(), about)


setup(
    name=about['__title__'],
    version=about['__version__'],
    author=about['__author__'],
    author_email=about['__author_email__'],
    description=about['__description__'],
    license=about['__license__'],
    url=about['__url__'],
    packages=find_packages(),
    keywords="gsp",
)
