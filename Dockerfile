########################################################################
#	Copyright (C) 2020        Sebastian Francisco Colomar Bauza
#	Copyright (C) 2020        Alejandro Colomar Andres
#	SPDX-License-Identifier:  GPL-2.0-only
########################################################################


FROM	"debian:unstable"

COPY	./	/usr/local/src/libalx/

WORKDIR	/usr/local/src/libalx/

RUN	apt-get update &&\
	apt-get upgrade --yes &&\
	apt-get install -V make --yes &&\
	yes | make prereq &&\
	apt-get autoremove --purge --yes &&\
	apt-get autoclean &&\
	apt-get clean

RUN	make &&\
	make install
