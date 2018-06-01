#include "TcpServer.h"

TcpServer::TcpServer(int port)
{
    int server_fd, valread, opt = 1;

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    int addrlen = sizeof(address);
      
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return;
    }
     
    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        return;
    }
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        return;
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        return;
    }
    if ((my_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        return;
    }
}

uint8_t TcpServer::read8()
{
    uint8_t data;
    read(my_socket, &data, 1);

    return data;
}

uint16_t TcpServer::read16()
{
    uint16_t data;
    uint8_t bytes[2];
    
    read(my_socket, bytes, 2);

    data = (bytes[0] << 8) + bytes[1];

    return data;
}

void TcpServer::send8(uint8_t data)
{
    send(my_socket, &data , 1 , 0);
}

void TcpServer::send16(uint16_t data)
{
    uint8_t bytes[2];
    
    bytes[0] = data >> 8;
    bytes[1] = data & 0xFF;

    send(my_socket, bytes, 2, 0);
}
