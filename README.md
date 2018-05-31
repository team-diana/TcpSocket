# TcpSocket
Easy interface for tcp sockets

## TcpServer
Easy way to create a tcp server



## TcpClient
Easy way to create a tcp client

+ **TcpClient::TcpClient(const char\* address, int port);** It create a tcp socket pointing at address:port
+ **TcpClient::send8(uint8_t data);** Send an 8 bit unsigned integer to the server
+ **TcpClient::send16(uint16_t data);** Send an 16 bit unsigned integer to the server
