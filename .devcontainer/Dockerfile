#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------

FROM olned/gcc-9-ubuntu

ENV DEBIAN_FRONTEND=noninteractive
ARG USERNAME=olned
ARG USER_UID=1000
ARG USER_GID=$USER_UID
# ARG CLANG_VERSION=7
# WORKDIR /workspaces

RUN set -xe; apt-get update \
    && apt-get -y upgrade \
    && apt-get -y install re2c python python3-dev python3-pip \
    && pip3 install lint pytest


# RUN set -xe; apt-get -y install \
#     clang-$CLANG_VERSION \
#     ninja-build \
#     llvm-$CLANG_VERSION \
#     libclang-$CLANG_VERSION-dev 
    # \     pybind11

RUN set -xe; groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    # [Optional] Add sudo support for the non-root user
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
    && chmod 0440 /etc/sudoers.d/$USERNAME

# ADD v1.10.0.tar.gz /home/olned/
# RUN cd /home/olned/ninja-1.10.0 && ./configure.py --bootstrap \
#     && chown -R olned:olned /home/olned/ninja-1.10.0

# RUN set -xe; git clone https://github.com/RosettaCommons/binder.git /home/olned/binder-src \
#     && cd /home/olned/binder-src \
#     && cmake CMakeLists.txt -DCMAKE_INSTALL_PREFIX:PATH=/home/olned/pybinder \
#     && make \
#     && make install \
#     && chown -R olned:olned /home/olned


# RUN set -xe; apt-get -y install \
#     libeigen3-dev \
#     libboost-all-dev \
#     catch


RUN set -xe; git clone https://github.com/pybind/pybind11.git /home/olned/pybind11 \
    && cd /home/olned/pybind11/ \
    && mkdir build && cd build \
    && cmake .. \
    && make check -j 4 \
    && make install \
    && chown -R olned:olned /home/olned/pybind11 \
    && pip3 install pybind11

# RUN update-alternatives --remove python /usr/bin/python2 \
#    && update-alternatives --install /usr/bin/python python /usr/bin/python3 10

ENV DEBIAN_FRONTEND=dialog
