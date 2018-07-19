#include "TcpClient.h"

#include <unistd.h>

int main()
{
    TcpClient *socket = new TcpClient("10.0.0.103", 50150);

    socket->send16(0);
    sleep(1);

    delete socket;
    return 0;
}
