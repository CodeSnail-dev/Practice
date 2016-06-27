project(Hello)
add_subdirectory(src bin)
add_subdirectory(libhello lib)


#SET( CMAKE_VERBOSE_MAKEFILE on )
#message(${PROJECT_SOURCE_DIR})
#set(SRC_LIST main.c)
#add_executable(Hello ${SRC_LIST})
#add_library(libHello hello.c)
#add_executable(Hello ${SRC_LIST})
#set_target_properties(libHello PROPERTIES OUTPUT_NAME "Hello")
#target_link_libraries(Hello libHello)
