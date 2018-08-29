#include "TcpClient.h"

#include <unistd.h>
#include <stdio.h>

int main()
{
    TcpClient *socket1 = new TcpClient("10.0.0.105", 50100);
    TcpClient *socket2 = new TcpClient("10.0.0.105", 50101);

    uint16_t data1, data2;

    while(true)
    {
        scanf("%hu", &data1);
        socket1->send16(data1);
        socket2->send16(data1);
    }

    delete socket;
    return 0;
}
