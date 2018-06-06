#include "TcpServer.h"

#include <iostream>

int main()
{
    uint16_t data16;
    while(true) {

        std::cout << "#Creating" << std::endl;
        TcpServer *server = new TcpServer(8088);
        std::cout << "#Created" << std::endl;
        while(server->read16(&data16))
        {
            printf("%c", data16);
        }

        std::cout << "Closing" << std::endl;
        delete server;
        std::cout << "Closed" << std::endl;
    }

    return 0;
}