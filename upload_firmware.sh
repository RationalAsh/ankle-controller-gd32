#!/bin/bash

#!/bin/sh
BINFILE="build/gd32-motor-controller.bin"
#echo $BINFILE 
st-flash --connect-under-reset write ${BINFILE} 0x8000000