FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    ninja-build \
    cmake \
    ccache \
    gcc \
    g++ \
    clang \
    gdb \
    valgrind \
    libgtest-dev \
    libbenchmark-dev \
 && rm -rf /var/lib/apt/lists/*