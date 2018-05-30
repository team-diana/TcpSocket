#include "TcpClient.h"

int main()
{
    TcpClient *socket = new TcpClient("127.0.0.1", 8088);

    socket->sendByte(1);

    return 0;
}
