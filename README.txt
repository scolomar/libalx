C/C++ library

This library provides extensions to glibc and other libraries (libbsd,
libcurl, OpenCV, GMP, GSL, ncurses, tesseract-ocr, zbar).

Dependencies:

base:
 - gcc-8
 - libbsd-dev
 - pkg-config

data-structures:
 + base

curl:
 + base
 - libcurl-*-dev

cv:
 + base
 - g++-8
 - libopencv-dev (>= 4)

gmp:
 + base
 - libgmp-dev  ||  libgmp3-dev

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

The majority of the library is licensed with LGPL-2.0-only, which basically
means that you can use it for whatever you want (open-source or closed-source),
but if you improve it, those improvements should be open-source.  Read
COPYING.txt for more information.
Some of it is licensed with BSD-2-Clause or Public Domain (explicitly stated).
