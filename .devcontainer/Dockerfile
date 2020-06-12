#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------

FROM olned/gcc-9-ubuntu

ENV DEBIAN_FRONTEND=noninteractive
ARG USERNAME=olned
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN set -xe; apt-get update \
    && apt-get -y upgrade \
    && apt-get -y install  python python3-dev python3-pip python3-venv ninja-build \
    && pip3 install -U autopep8 pylint pytest twine setuptools wheel pybind11


RUN set -xe; groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    # [Optional] Add sudo support for the non-root user
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME\
    && chmod 0440 /etc/sudoers.d/$USERNAME


ENV DEBIAN_FRONTEND=dialog
