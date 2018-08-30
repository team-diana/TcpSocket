#include "TcpClient.h"

#include <unistd.h>
#include <stdio.h>

#define IP "10.0.0.100"

int main()
{
    TcpClient *socket1 = new TcpClient(IP, 50100);
    TcpClient *socket2 = new TcpClient(IP, 50101);

    uint16_t data1, data2;

    while(true)
    {
        scanf("%hu", &data1);
        socket1->send16(data1);
        if(!socket1->isConnected())
        {
          do
          {
            printf("Reconnecting!\n");
            socket1 = new TcpClient(IP, 50100);
          } while(socket1 != NULL);

          socket1->send16(data1);
        }

        socket2->send16(data1);
        if(!socket2->isConnected())
        {
          do
          {
            printf("Reconnecting!\n");
            socket2 = new TcpClient(IP, 50101);
          } while(socket2 != NULL);

          socket2->send16(data1);
        }
    }

    printf("Closing!\n");

    delete socket1;
    delete socket2;
    return 0;
}
