# GD32 Motor Controller Source Codes

# How to build
Make sure you have docker installed.

First build the docker image locally (optional).

```bash
docker build -t arm-toolchain .
```

Then run the docker container with the following command (unix).

```bash
docker run --rm -v $(pwd):/workspace -w /workspace ashwinnarayan1994/arm-toolchain bash -c "./build.sh"
```

And the following command (PowerShell)

```powershell
docker run --rm -v ${PWD}:/workspace -w /workspace ashwinnarayan1994/arm-toolchain bash -c "./build.sh"
```

This command 
1. Mounts the current directory to the `/workspace` directory in the container.
2. Sets the working directory to `/workspace`.
3. Runs the `build.sh` script.

The `build.sh` script will build the source codes and generate the binary files in the `build` directory as gd32-motor-controller.bin which is ready for flashing into microcontroller. 