#pragma once

#ifdef _WIN32
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif


enum class SocketServerUDPCodes
{
    STATUS_OK = 0,
    WSA_STARTUP_ERROR = 1,
    CREATE_SOCKET_ERROR = 2,
    BIND_ERROR = 3
};

class SocketServerUDP
{

public:
    SocketServerUDP (int local_port);
    ~SocketServerUDP ()
    {
        close ();
    }

    int bind (int min_bytes = 1);
    int recv (void *data, int size);
    void close ();

private:
    int local_port;
    struct sockaddr_in server_addr;

#ifdef _WIN32
    SOCKET server_socket;
#else
    int server_socket;
#endif
};