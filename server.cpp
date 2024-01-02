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
        perror("socket");//기존 error handling
        return 1;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);

    // 서버 소켓에 주소 바인딩
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind");
        return 1;
    }

    // 클라이언트의 연결을 대기
    if (listen(serverSocket, 5) < 0) {
        perror("listen");
        return 1;
    }

    cout << "8888 open" << endl;

    while (true) {
        // 클라이언트의 연결을 수락하고 새로운 소켓 생성
        sockaddr_in clientAddress;
        socklen_t clientAddrLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);
        if (clientSocket < 0) {
            perror("accept");
            continue;
        }

        // 새로운 클라이언트에 대해 별도의 스레드 생성하여 처리
        thread clientThread(handleClient, clientSocket);
        clientThread.detach();  // 스레드를 백그라운드로 실행
    }
    // 서버 소켓 닫기
    close(serverSocket);

    return 0;
}
void handleClient(int clientSocket) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // 클라이언트로부터 데이터 읽기
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        perror("recv");
        close(clientSocket);
        return;
    }

    // 받은 데이터 출력
    std::cout << "Received from client: " << buffer << std::endl;

    // 클라이언트에게 응답 보내기
    const char* response = "Hello from server!";
    send(clientSocket, response, strlen(response), 0);

    // 클라이언트 소켓 닫기
    close(clientSocket);
}