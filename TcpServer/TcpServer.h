#ifndef TCPSERVER
#define TCPSERVER

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <vector>

class TcpServer
{
    public:
        TcpServer(int port);
        ~TcpServer();

        uint8_t read8();
        uint16_t read16();

        void send8(uint8_t data);
        void send16(uint16_t data);

    private:
        int port;
        int my_socket;
        std::vector<uint8_t> buffer8;
        std::vector<uint16_t> buffer16;
        
        uint8_t buffer;
};

#endif