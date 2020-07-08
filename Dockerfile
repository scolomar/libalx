################################################################################
##      Copyright (C) 2020        Sebastian Francisco Colomar Bauza           ##
##      Copyright (C) 2020        Alejandro Colomar Andrés                    ##
##      SPDX-License-Identifier:  GPL-2.0-only                                ##
################################################################################


################################################################################
FROM	"debian:testing"
################################################################################
RUN									\
	apt-get update							&& \
	apt-get upgrade --yes						&& \
	apt-get install -V \
			gcc-10 \
			g++-10 \
			make \
			git \
			pkg-config \
			libbsd-dev \
			libcurl4-openssl-dev \
			libgmp3-dev \
			libgsl-dev \
			libncurses-dev \
			libopencv-dev \
			libtesseract-dev \
			libzbar-dev \
			telnet \
			gnuplot \
			deborphan \
			--yes						&& \
	apt-get autoremove --purge --yes				&& \
	apt-get autoclean						&& \
	apt-get clean

################################################################################
COPY	./	/usr/local/src/libalx/
################################################################################
WORKDIR	/usr/local/src/libalx/
################################################################################
RUN									\
	make								&& \
	make install

################################################################################







