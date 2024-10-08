file(GLOB_RECURSE SLX_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(simulink ${SLX_SRCS})

target_include_directories(simulink PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#target_compile_definitions(simulink PUBLIC
#        MODEL=shoulder1dof_gyems
#        NUMST=1
#        NCSTATES=0
#        HAVESTDIO
#        MODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
#        CLASSIC_INTERFACE=0
#        ALLOCATIONFCN=0
#        TID01EQ=0
#        TERMFCN=0
#        ONESTEPFCN=1
#        MAT_FILE=0
#        MULTI_INSTANCE_CODE=1
#        INTEGER_CODE=0
#        MT=0
#)