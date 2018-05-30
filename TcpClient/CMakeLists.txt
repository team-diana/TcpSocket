cmake_minimum_required(VERSION 3.3)

project(TcpSocket)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIB_SRC TcpSocket.h TcpSocket.cpp test.cpp)
add_executable(TcpSocket ${LIB_SRC})