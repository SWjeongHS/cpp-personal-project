#include <iostream>
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


void handleClient(int clientSocket);

int main(void) {
    using namespace std;

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0) {
        perror("socket");//���� error handling
        return 1;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);

    // ���� ���Ͽ� �ּ� ���ε�
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind");
        return 1;
    }

    // Ŭ���̾�Ʈ�� ������ ���
    if (listen(serverSocket, 5) < 0) {
        perror("listen");
        return 1;
    }

    cout << "8888 open" << endl;

    while (true) {
        // Ŭ���̾�Ʈ�� ������ �����ϰ� ���ο� ���� ����
        sockaddr_in clientAddress;
        socklen_t clientAddrLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);
        if (clientSocket < 0) {
            perror("accept");
            continue;
        }

        // ���ο� Ŭ���̾�Ʈ�� ���� ������ ������ �����Ͽ� ó��
        thread clientThread(handleClient, clientSocket);
        clientThread.detach();  // �����带 ��׶���� ����
    }
    // ���� ���� �ݱ�
    close(serverSocket);

    return 0;
}
void handleClient(int clientSocket) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Ŭ���̾�Ʈ�κ��� ������ �б�
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        perror("recv");
        close(clientSocket);
        return;
    }

    // ���� ������ ���
    std::cout << "Received from client: " << buffer << std::endl;

    // Ŭ���̾�Ʈ���� ���� ������
    const char* response = "Hello from server!";
    send(clientSocket, response, strlen(response), 0);

    // Ŭ���̾�Ʈ ���� �ݱ�
    close(clientSocket);
}