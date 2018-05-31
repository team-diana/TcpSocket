cmake_minimum_required(VERSION 3.3)

project(TcpServer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIB_SRC TcpServer.h TcpServer.cpp test.cpp)
add_executable(TcpServer ${LIB_SRC})