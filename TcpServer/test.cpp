#include "TcpServer.h"

#include <stdio.h>
#include <unistd.h>

int main()
{
    TcpServer *server1 = new TcpServer(50100);
    server1->start16();
    TcpServer *server2 = new TcpServer(50101);
    server2->start16();

    uint16_t data = 0;

    while(data != 99)
    {
        if(server1->newDataAvailable())
        {
            data = server1->readLast16();
            printf("%hu\n", data);
        }
    }

    delete(server1);
    delete(server2);

    return 0;
}
