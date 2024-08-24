cmake_minimum_required(VERSION 3.15.3)
project(gd32-motor-controller)

enable_language(C ASM CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CX_STANDARD 11)
set(CMAKE_C)
set(EXECUTABLE ${PROJECT_NAME}.out)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake")

# Source directories
set(CMSIS_DIR "${CMAKE_SOURCE_DIR}/src/CMSIS")
set(STD_PERIPH_DIR "${CMAKE_SOURCE_DIR}/src/GD32F4xx_standard_peripheral")
set(BSP_DIR "${CMAKE_SOURCE_DIR}/src/BSP")

file(GLOB_RECURSE CMSIS_SOURCES "${CMSIS_DIR}/*.c")
file(GLOB_RECURSE STD_PERIPH_SOURCES "${STD_PERIPH_DIR}/*.c")
file(GLOB_RECURSE BSP_SOURCES "${BSP_DIR}/*.c")
set(STARTUP_FILE "${CMAKE_SOURCE_DIR}/src/CMSIS/GD/GD32F4xx/Source/GCC/startup_gd32f405_425.S")

# Concatenate all the lists into one
set(ALL_C_SOURCES "src/main.cpp" ${CMSIS_SOURCES} ${STD_PERIPH_SOURCES} ${BSP_SOURCES} ${STARTUP_FILE})

add_executable(${EXECUTABLE} ${ALL_C_SOURCES}) 

target_compile_definitions(${EXECUTABLE} PRIVATE
        -DGD32F425
        )

target_include_directories(${EXECUTABLE} PRIVATE
        "${BSP_DIR}"
        "${CMSIS_DIR}"
        "${CMSIS_DIR}/GD/GD32F4xx/Include"
        "${STD_PERIPH_DIR}/Include"
        )

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

