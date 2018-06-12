# TcpSocket
Easy interface for tcp sockets

## TcpServer
Easy way to create a tcp server

+ **TcpServer::TcpServer(int port)** Bind a socket server to the specified port
+ **void TcpServer::start8()** Start the server with an 8 bit socket
+ **void TcpServer::start16()** Start the server with a 16 bit socket
+ **uint8_t TcpServer::readLast8()** Read the last data received from the 8 bit socket
+ **uint16_t TcpServer::readLast16()** Read the last data received from the 16 bit socket

## TcpClient
Easy way to create a tcp client

+ **TcpClient::TcpClient(const char\* address, int port);** Create a tcp socket pointing at address:port
+ **void TcpClient::send8(uint8_t data);** Send an 8 bit unsigned integer to the server
+ **void TcpClient::send16(uint16_t data);** Send a 16 bit unsigned integer to the server
