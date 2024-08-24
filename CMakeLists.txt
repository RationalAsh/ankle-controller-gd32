cmake_minimum_required(VERSION 3.15.3)
project(gd32-motor-controller)

set(STM32_CHIP "STM32L432xx" CACHE STRING "")
set(STM32_CHIP_FAMILY "STM32L4" CACHE STRING "")

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/gcc_stm32.cmake CACHE PATH "")


