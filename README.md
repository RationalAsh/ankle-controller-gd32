# GD32 Motor Controller Source Codes

# How to build
Make sure you have docker installed.

First build the docker image locally.

```bash
docker build -t arm-toolchain-alpine .
```

Then run the docker container with the following command.

```bash
docker run --rm -v $(pwd):/workspace -w /workspace arm-toolchain-alpine bash -c "./build.sh"
```

This command 
1. Mounts the current directory to the `/workspace` directory in the container.
2. Sets the working directory to `/workspace`.
3. Runs the `build.sh` script.

The `build.sh` script will build the source codes and generate the binary files in the `build` directory as gd32-motor-controller.bin which is ready for flashing into microcontroller. 