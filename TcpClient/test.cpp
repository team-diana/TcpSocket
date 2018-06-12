#include "TcpClient.h"

#include <unistd.h>

int main()
{
    TcpClient *socket = new TcpClient("127.0.0.1", 8088);

    for(uint8_t i = 0; i < 10; i++)
    {
        socket->send8(i);
        usleep(100000);
    }

    delete socket;
    return 0;
}
