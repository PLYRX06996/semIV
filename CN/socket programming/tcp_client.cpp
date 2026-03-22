#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main() {
    int sock;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    char msg[] = "Hello Server";
    send(sock, msg, strlen(msg), 0);

    recv(sock, buffer, sizeof(buffer), 0);
    cout << "Server : " << buffer << endl;

    close(sock);
    return 0;
}