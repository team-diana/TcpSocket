#include "TcpClient.h"

int main()
{
    TcpClient *socket = new TcpClient("127.0.0.1", 8088);

    socket->send8(256);
    socket->send16(256);
    socket->send16(256);
    uint16_t data16 = socket->read16();

    printf("%hu\n", data16);

    return 0;
}
