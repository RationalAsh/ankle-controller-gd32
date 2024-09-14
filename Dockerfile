# Image that will be used to build the application

# Use an official Alpine image as a base
FROM alpine:3.20.3

# Install dependencies
RUN apk add --no-cache \
    wget \
    bash \
    xz \
    python3 \
    py3-pip \
    cmake \
    make \
    g++ \
    libc-dev

# Download and extract ARM GNU toolchain
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu/13.3.rel1/binrel/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz \
    && tar -xvf arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz -C /opt \
    && rm arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz

# Add the toolchain binaries to the PATH
ENV PATH="/opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin:$PATH"

# Add libc6-compat to the image
RUN apk add --no-cache libc6-compat gcc-arm-none-eabi

# Verify the installation of Python, CMake, and ARM toolchain
RUN python3 --version && cmake --version binutils-arm-none-eabi 
# Print out the PATH
RUN echo $PATH
# Print the version of the ARM toolchain
RUN arm-none-eabi-gcc --version && arm-none-eabi-g++ --version

# Set a working directory
WORKDIR /workspace

# Define the default command
CMD ["/bin/bash"]