set(LIB_SRC mainTest.cpp)
add_definitions("-DLIBHELLO_BUILD")
add_library(NavHMI SHARED ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#set_target_properties(NavHMI PROPERTIES OUTPUT_NAME "hello")