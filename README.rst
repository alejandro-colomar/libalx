
======
libalx
======

C/C++ library.
This library provides extensions to glibc and other libraries.

Modules and dependencies:
~~~~~~~~~~~~~~~~~~~~~~~~~

base:
	- gcc (>= 10)
	- libbsd-dev
	- pkg-config

data-structures:
	+ base

robot:
	+ base

cv:
	+ base
	+ gsl
	- g++ (>= 10)
	- libopencv-dev (>= 4)

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

plot:
	+ base
	- gnuplot

telnet-tcp:
	+ base
	- telnet

zbar:
	+ base
	- libzbar-dev

The majority of the library is licensed with LGPL-2.0-only, which basically
means that you can use it for whatever you want (open-source or closed-source),
but if you improve it, those improvements should be open-source.  Read
COPYING.txt for more information.
Some of it is licensed with BSD-2-Clause or Public Domain (explicitly stated).

To read the full text of the main license, see COPYING.txt;  to read licenses
that apply to some files only, search the license identifier here:
https://spdx.org/licenses/
