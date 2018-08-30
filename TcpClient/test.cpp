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
        if(!socket1->isConnected())
        {
          while(!socket1->isConnected())
          {
            printf("Reconnecting!\n");
            delete(socket1);
            socket1 = new TcpClient("10.0.0.105", 50100);
          }

          socket1->send16(data1);
        }

        socket2->send16(data1);
        if(!socket2->isConnected())
        {
          while(!socket2->isConnected())
          {
            printf("Reconnecting!\n");
            delete(socket2);
            socket2 = new TcpClient("10.0.0.105", 50100);
          }

          socket2->send16(data1);
        }
    }

    delete socket1;
    delete socket2;
    return 0;
}
