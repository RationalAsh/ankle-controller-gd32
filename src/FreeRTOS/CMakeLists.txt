add_library(freertos_kernel STATIC)

file(GLOB FREERTOS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

target_sources(freertos_kernel FREERTOS_SOURCES)