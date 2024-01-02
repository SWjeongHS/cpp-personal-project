#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void) {
    // Ŭ���̾�Ʈ ���� ����
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("socket");
        return 1;
    }

    // ���� �ּ� ����
    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);

    // ���� �ּҸ� ��Ʈ��ũ �ּҷ� ��ȯ
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // ������ ����
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("connect");
        return 1;
    }

    // ������ ������ ����
    char *message = "Hello from client!";
    send(clientSocket, message, strlen(message), 0);

    // �����κ��� ���� �ޱ�
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        perror("recv");
        return 1;
    }

    // ���� ���� ���
    std::cout << "Received from server: " << buffer << std::endl;

    // Ŭ���̾�Ʈ ���� �ݱ�
    close(clientSocket);

    return 0;
}