#include "TcpServer.h"

int main()
{
    TcpServer *server = new TcpServer(8088);

    uint8_t data8 = server->read8();
    uint16_t data16 = server->read16();

    printf("%hhu\n%hu\n", data8, data16);

    return 0;
}