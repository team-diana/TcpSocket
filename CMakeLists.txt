cmake_minimum_required(VERSION 3.3)

project(TcpSocket)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)


set(SERVER_SRC TcpServer/TcpServer.h TcpServer/TcpServer.cpp TcpServer/test.cpp)
add_executable(TcpServer ${SERVER_SRC})
TARGET_LINK_LIBRARIES( TcpServer pthread)

set(CLIENT_SRC TcpClient/TcpClient.h TcpClient/TcpClient.cpp TcpClient/test.cpp)
add_executable(TcpClient ${CLIENT_SRC})
