#include "TcpServer.h"

#include <stdio.h>
#include <unistd.h>

int main()
{
    TcpServer *server = new TcpServer(8088);
    server->start16();

    while(true)
    {
        if(server->newDataAvailable())
        {
            uint16_t data = server->readLast16();
            printf("%hu\n", data);
        }
    }

    return 0;
}
