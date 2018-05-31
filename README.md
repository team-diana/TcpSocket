# TcpSocket
Easy interface for tcp sockets

## TcpServer
Easy way to create a tcp server

+ **TcpServer::TcpServer(int port)** Bind a socket server to the specified port
+ **uint8_t TcpServer::read8()** Read an 8 bit unsigned integer from the socket
+ **uint8_t TcpServer::read16()** Read a 16 bit unsigned integer from the socket


## TcpClient
Easy way to create a tcp client

+ **TcpClient::TcpClient(const char\* address, int port);** Create a tcp socket pointing at address:port
+ **void TcpClient::send8(uint8_t data);** Send an 8 bit unsigned integer to the server
+ **void TcpClient::send16(uint16_t data);** Send a 16 bit unsigned integer to the server
