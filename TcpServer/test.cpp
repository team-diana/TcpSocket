#include "TcpServer.h"

#include <stdio.h>
#include <unistd.h>

int main()
{
    TcpServer *server1 = new TcpServer(50100);
    server1->start16();
    TcpServer *server2 = new TcpServer(50101);
    server2->start16();

    while(true)
    {
        if(server1->newDataAvailable())
        {
            uint16_t data = server1->readLast16();
            printf("%hu\n", data);
        }
    }

    return 0;
}
