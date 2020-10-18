C/C++ library

This library provides extensions to glibc and other libraries (libbsd, OpenCV,
GMP, GSL, ncurses, tesseract-ocr, zbar).

Dependencies:

base:
 - gcc-8
 - libbsd-dev

cv:
 + base
 - g++-8
 - libopencv-dev (>= 3)

gmp:
 + base
 - libgmp-dev

gsl:
 + base
 - libgsl-dev

ncurses:
 + base
 - libncurses-dev

ocr:
 + base
 - libtesseract-dev

zbar:
 + base
 - libzbar-dev

The majority of the library is licensed with LGPL-2.0-only
The nix module (not yet available) is licensed with BSD-2-Clause
