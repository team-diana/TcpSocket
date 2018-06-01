#ifndef TCPCLIENT
#define TCPCLIENT

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

class TcpClient
{
    public:
        TcpClient(const char* address, int port);
        ~TcpClient();

        void send8(uint8_t data);
        void send16(uint16_t data);

        uint8_t read8();
        uint16_t read16();

    private:
        int sock;
        int port;
        char address[16];
};

#endif
