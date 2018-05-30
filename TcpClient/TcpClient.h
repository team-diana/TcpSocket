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

        void sendByte(uint8_t data);

    private:
        int sock;
        int port;
        char address[16];
};

#endif
