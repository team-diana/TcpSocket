cmake_minimum_required(VERSION 3.3)

project(TcpClient)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIB_SRC TcpClient.h TcpClient.cpp test.cpp)
add_executable(TcpClient ${LIB_SRC})
