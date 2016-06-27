cmake_minimum_required(VERSION 2.8)
project(helloworld)
find_package(Qt4 4.8 COMPONENTS QtCore QtGui QtOpenGL QtXmlPatterns QtNetwork REQUIRED)
message(Status "abc ${CMAKE_MODULE_PATH}")