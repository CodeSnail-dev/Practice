set(LIB_SRC NavShell.cpp)
add_library(libNavShell SHARED ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libNavShell PROPERTIES OUTPUT_NAME "NavShell")