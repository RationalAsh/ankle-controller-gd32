#!/bin/bash
# Script to build the project

# List of valid build types
valid_build_types=("Debug" "Release" "Fresh")

# Check the first argument to see if it is a valid build type
# if no argument is provided, default to Debug
if [ -z "$1" ]; then
    build_type="Debug"
else
    if [[ " ${valid_build_types[@]} " =~ " $1 " ]]; then
        build_type=$1
    else
        echo "Invalid build type: $1"
        echo "Valid build types are: ${valid_build_types[@]}"
        exit 1
    fi
fi

# Echo the build type
echo "Building project with build type: $build_type"


# Create the build directory if it doesn't exist
mkdir -p build

# Change to the build directory for the remaining commands
cd build

# Check that we are in the build directory
echo "Running build in $(pwd)"

# If the build type is Fresh
if [ "$build_type" == "Fresh" ]; then
    cmake -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi-gcc.cmake .. --fresh
fi

# If the directory is empty then run cmake
if [ ! -f "CMakeCache.txt" ]; then
    cmake -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi-gcc.cmake ..
fi

# Run the build command
cmake --build . -- -j 4