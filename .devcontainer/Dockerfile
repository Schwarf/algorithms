FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04
RUN apt-get update && apt-get install -y \
    build-essential ninja-build cmake clang lld gdb valgrind libgtest-dev libbenchmark-dev \
 && cmake -S /usr/src/googletest -B /usr/src/googletest/build \
 && cmake --build /usr/src/googletest/build -j \
 && cp /usr/src/googletest/build/lib/*.a /usr/lib/ \
 && rm -rf /var/lib/apt/lists/*