#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

using namespace std;

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    cout << "UDP server running...\n";

    len = sizeof(clientAddr);

    memset(buffer, 0, sizeof(buffer));

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&clientAddr, &len);

    int a, b;
    sscanf(buffer, "%d %d", &a, &b);

    cout << "Numbers received: " << a << " and " << b << endl;

    int sum = a + b;

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%d", sum);

    sendto(sockfd, buffer, strlen(buffer), 0,
           (struct sockaddr*)&clientAddr, len);

    close(sockfd);
    return 0;
}