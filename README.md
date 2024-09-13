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