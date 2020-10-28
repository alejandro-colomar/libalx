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
			g++ \
			gcc \
			git \
			gnuplot \
			make \
			libbsd-dev \
			libcurl4-openssl-dev \
			libgmp3-dev \
			libgsl-dev \
			libncurses-dev \
			libopencv-dev \
			libtesseract-dev \
			libzbar-dev \
			pkg-config \
			telnet \
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







