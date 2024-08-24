cmake_minimum_required(VERSION 3.15.3)
project(gd32-motor-controller)

set(STM32_CHIP "GD32F425" CACHE STRING "")
set(STM32_CHIP_FAMILY "GD32F4xx" CACHE STRING "")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(TOOLCHAIN_PREFIX arm-none-eabi-)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_OBJCOPY ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}size CACHE INTERNAL "size tool")
set(EXECUTABLE ${PROJECT_NAME}.out)
set(CMAKE_FIND_ROOT_PATH ${BINUTILS_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Source directories
set(CMSIS_DIR "${CMAKE_SOURCE_DIR}/src/CMSIS")
set(STD_PERIPH_DIR "${CMAKE_SOURCE_DIR}/src/GD32F4xx_standard_peripheral")

file(GLOB_RECURSE CMSIS_SOURCES "${CMSIS_DIR}/*.c")
file(GLOB_RECURSE CMSIS_SOURCES "${CMSIS_DIR}/*.c")

add_executable(${EXECUTABLE} ${CMSIS_SOURCES}) 

target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard

        -fdata-sections
        -ffunction-sections

        -Wall

        $<$<CONFIG:Debug>:-Og>
        )

target_link_options(${EXECUTABLE} PRIVATE
        -T${CMAKE_SOURCE_DIR}/BSP/STM32F413ZHTx_FLASH.ld
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -specs=nano.specs
        -lc
        -lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        )


set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/gcc_stm32.cmake CACHE PATH "")


