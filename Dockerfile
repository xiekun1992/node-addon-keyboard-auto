FROM xkfront/ubuntu:1804cn

# set `ARG DEBIAN_FRONTEND=noninteractive` will not solve `debconf: delaying package configuration, since apt-utils is not installed`, leave it alone

# WARNING: apt does not have a stable CLI interface. Use with caution in scripts. Use "apt-get" instead than "apt"
RUN apt-get update

RUN apt-get install -y wget xz-utils 
RUN apt-get install -y git
RUN apt-get install -y python make g++ libx11-dev libxtst-dev

WORKDIR /root

RUN wget https://nodejs.org/dist/v12.16.3/node-v12.16.3-linux-x64.tar.xz
RUN xz -d node-v12.16.3-linux-x64.tar.xz \
	&& tar xvf node-v12.16.3-linux-x64.tar \
	&& mv node-v12.16.3-linux-x64 node \ 
	&& rm node-v12.16.3-linux-x64.tar

ENV PATH $PATH:/root/node/bin
