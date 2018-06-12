#include "TcpServer.h"

#include <stdio.h>
#include <unistd.h>

int main()
{
    TcpServer *server = new TcpServer(8088);
    server->start8();

    while(true)
    {
        if(server->newDataAvailable())
        {
            uint8_t data = server->readLast8();
            printf("%hhu\n", data);
        }
    }

    return 0;
}