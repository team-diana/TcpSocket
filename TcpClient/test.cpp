#include "TcpClient.h"

#include <unistd.h>

int main()
{
    TcpClient *socket = new TcpClient("127.0.0.1", 8088);

    socket->send16(256);

    delete socket;
    return 0;
}
