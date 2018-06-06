#include "TcpClient.h"

#include <unistd.h>

int main()
{
    TcpClient *socket = new TcpClient("127.0.0.1", 8088);

    char c;
    do {
        c = getchar();
        socket->send16(c);
    } while (c != '0');

    delete socket;
/*
    for(uint16_t i = 0; i < 5; i++)
    {
    	socket->send16(i);
        sleep(2);
    }
*/
    return 0;
}
