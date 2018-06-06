#include "TcpClient.h"

#include <unistd.h>

int main()
{
    TcpClient *socket = new TcpClient("10.0.0.100", 8088);

    char c;

    do
    {
        c = getchar();
        socket->send8(c);
    } while (c != '0');

    delete socket;
    return 0;
}
