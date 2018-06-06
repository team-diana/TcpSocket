#include "TcpServer.h"

#include <iostream>

int main()
{
    uint8_t data8;
    while(true)
    {
        TcpServer *server = new TcpServer(8088);

        while(server->read8(&data8))
        {
            printf("%c", data8);
        }

        delete server;
    }

    return 0;
}