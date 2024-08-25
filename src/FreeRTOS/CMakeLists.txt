file(GLOB FREERTOS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_library(freertos_kernel STATIC ${FREERTOS_SOURCES})

target_include_directories(freertos_kernel PUBLIC
    include
    SYSTEM_INCLUDE_DIR
)

target_link_libraries(freertos_kernel bsp)