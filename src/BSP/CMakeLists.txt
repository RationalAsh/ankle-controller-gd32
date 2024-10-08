set(CMSIS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/CMSIS")
set(STD_PERIPH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/GD32F4xx_standard_peripheral")
set(BSP_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE CMSIS_SOURCES "${CMSIS_DIR}/*.c")
file(GLOB_RECURSE STD_PERIPH_SOURCES "${STD_PERIPH_DIR}/*.c")
file(GLOB_RECURSE BSP_SOURCES "${BSP_DIR}/*.c")
set(STARTUP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/GD/GD32F4xx/Source/GCC/startup_gd32f405_425.S")

# Concatenate all the lists into one
set(ALL_C_SOURCES ${CMSIS_SOURCES} ${STD_PERIPH_SOURCES} ${BSP_SOURCES} ${STARTUP_FILE})

add_library(bsp STATIC ${ALL_C_SOURCES})

target_compile_definitions(bsp PUBLIC
        -DGD32F425
        -D__FPU_PRESENT
        )

target_compile_options(bsp PUBLIC
        -Wno-implicit
        -fsingle-precision-constant
        -Wno-strict-aliasing
        -Wno-conversion
        -Wno-implicit
        -g
)

target_include_directories(bsp PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${BSP_DIR}"
        "${CMSIS_DIR}"
        "${CMSIS_DIR}/GD/"
        "${CMSIS_DIR}/DSP/Include"
        "${CMSIS_DIR}/GD/GD32F4xx/Include"
        "${STD_PERIPH_DIR}/Include"
        )