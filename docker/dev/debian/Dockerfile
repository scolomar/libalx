FROM	debian:testing
RUN	apt-get update							&& \
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
			deborphan \
			--yes						&& \
	apt-get autoremove --purge --yes				&& \
	apt-get purge $(deborphan) --yes				&& \
	apt-get autoclean						&& \
	apt-get clean

WORKDIR	/tmp
RUN	git clone https://github.com/alejandro-colomar/libalx.git	&& \
	make		-C libalx					&& \
	make install	-C libalx					&& \
	rm -rf libalx


### Use this container to build programs that depend on libalx.
### To run the machine (coding and compiling the program can be done here):
### This needs to be called from the parent directory where the program is.
## $ docker container run --user $(id -u):$(id -g) --tty --interactive --volume $PWD:$PWD --workdir $PWD --name libalx-dev alejandrocolomar/libalx:dev bash

### To work on the code and compile the program:
## $ docker container start libalx-dev
## $ docker container attach libalx-dev

### To install the program:
## $ docker container start libalx-dev
## $ docker container exec --user root --workdir $PWD libalx-dev make install --directory <repository_dir>

### To run a root terminal (other uses):
## $ docker container start libalx-dev
## $ docker container exec --user root --tty --interactive --workdir $PWD libalx-dev bash

