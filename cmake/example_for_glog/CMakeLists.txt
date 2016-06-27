project(Hello)
SET( CMAKE_VERBOSE_MAKEFILE on )
message(${PROJECT_SOURCE_DIR})
set(SRC_LIST main.cpp hello.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include
					${PROJECT_SOURCE_DIR}/include/Common)
add_executable(Hello ${SRC_LIST})
target_link_libraries(Hello ${PROJECT_SOURCE_DIR}/lib/libglog.lib)