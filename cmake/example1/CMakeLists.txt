project(Hello)
SET( CMAKE_VERBOSE_MAKEFILE on )
message(${PROJECT_SOURCE_DIR})
set(SRC_LIST main.c hello.c)
#add_executable(Hello ${SRC_LIST})
#add_library(libHello ${SRC_LIST})
add_library(libHello SHARED ${SRC_LIST})
add_executable(Hello ${SRC_LIST})