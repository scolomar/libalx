FROM	debian:testing
RUN	apt-get update							&& \
	apt-get upgrade --yes						&& \
	apt-get install -V \
			gcc \
			g++ \
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
	apt-get purge $(deborphan) --yes				&& \
	apt-get autoclean						&& \
	apt-get clean


### Use this container to build and test libalx.
### To run the machine (coding and compiling libalx can be done here):
### This needs to be called from the parent directory where the programs are.
## $ docker container run --user $(id -u):$(id -g) --tty --interactive --volume $PWD:$PWD --workdir $PWD --name libalx-devel alejandrocolomar/libalx:devel bash

### To work on the code and compile libalx:
## $ docker container start libalx-devel
## $ docker container attach libalx-devel

### To install libalx:
## $ docker container start libalx-devel
## $ docker container exec --user root --workdir $PWD libalx-devel make install --directory libalx

### To run a root terminal (other uses):
## $ docker container start libalx-devel
## $ docker container exec --user root --tty --interactive --workdir $PWD libalx-devel bash

