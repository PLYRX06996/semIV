#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);

    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    int a = 5, b = 7;

    sprintf(buffer, "%d %d", a, b);

    sendto(sockfd, buffer, strlen(buffer), 0,
           (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    memset(buffer, 0, sizeof(buffer));

    recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);

    cout << "Sum from server: " << buffer << endl;

    close(sockfd);
    return 0;
}