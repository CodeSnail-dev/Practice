cmake_minimum_required(VERSION 2.8.10)

project(QtApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(${APPLE})
elseif(${WIN32})
    #   set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.4.1/5.4/msvc2013_opengl/lib/cmake")
    find_package(Qt4 4.8 COMPONENTS QtCore QtGui QtOpenGL QtXmlPatterns QtNetwork REQUIRED)
endif()

include_directories(
	${CMAKE_SOURCE_DIR}/include
)

# Qt demo executable
add_executable(qtdemo MACOSX_BUNDLE
	${CMAKE_SOURCE_DIR}/main.cpp
)

target_link_libraries( qtdemo Qt4::QtGui)
