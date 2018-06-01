#include "TcpClient.h"

TcpClient::TcpClient(const char* address, int port)
{
    this->port = port;
    strcpy(this->address, address);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, address, &serv_addr.sin_addr) <= 0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return;
    }
}

void TcpClient::send8(uint8_t data)
{
    send(sock , &data , 1 , 0);
}

void TcpClient::send16(uint16_t data)
{
    uint8_t bytes[2];
    
    bytes[0] = data >> 8;
    bytes[1] = data & 0xFF;

    send(sock, bytes, 2, 0);
}

uint8_t TcpClient::read8()
{
    uint8_t data;
    read(sock, &data, 1);

    return data;
}

uint16_t TcpClient::read16()
{
    uint16_t data;
    uint8_t bytes[2];
    
    read(sock, bytes, 2);

    data = (bytes[0] << 8) + bytes[1];

    return data;
}