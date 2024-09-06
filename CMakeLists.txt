cmake_minimum_required(VERSION 3.15.3)
project(gd32-motor-controller)

enable_language(C ASM CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C)
set(EXECUTABLE ${PROJECT_NAME}.out)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake")
set(SYSTEM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/BSP/CMSIS/GD/GD32F4xx/Include")


add_compile_options(
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -fdata-sections
        -ffunction-sections
        -Wdouble-promotion
        -Wall
        -Wextra
        -fshort-enums 
        -ffast-math
        -Os
)

add_compile_definitions(
        -DGD32F425
        -DARM_MATH_CM4
)

add_subdirectory("${CMAKE_SOURCE_DIR}/src/BSP")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/FreeRTOS")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/Simulink")

add_executable(${EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/main.cpp") 

target_link_libraries(${EXECUTABLE} LINK_PUBLIC
        bsp
        freertos_kernel
        simulink
)

target_link_options(${EXECUTABLE} PRIVATE
        -T${CMAKE_SOURCE_DIR}/src/BSP/gd32f425.ld
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -specs=nosys.specs
        -lc
        -lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        )

# Print executable size
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-size ${EXECUTABLE})

# Create hex file
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)

add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objdump -d --no-show-raw-insn -marm ${PROJECT_NAME}.out > ${PROJECT_NAME}.asm
        COMMAND arm-none-eabi-objdump -s -j .isr_vector ${PROJECT_NAME}.out > ${PROJECT_NAME}.isr_vector)

