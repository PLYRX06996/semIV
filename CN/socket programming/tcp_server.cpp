#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

using namespace std;

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    listen(serverSocket, 5);
    cout << "Waiting for client.\n";

    clientSocket = accept(serverSocket, NULL, NULL);

    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Client: " << buffer << endl;

    char reply[] = "Message Received.";
    send(clientSocket, reply, strlen(reply), 0);

    close(clientSocket);
    close(serverSocket);

    return 0;
}