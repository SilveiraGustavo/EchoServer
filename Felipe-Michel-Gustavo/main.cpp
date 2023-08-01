/*
    ENGENHARIA DE COMPUTAÇÃO - IFMG CAMPUS BAMBUÍ
    DISCIPLINA: REDES DE COMPUTADORES
    PROFESSOR : SAMUEL DIAS


    FELIPE SOARES BARBOSA - RA 0073499
    GUSTAVO SILVEIRA DIAS - RA 0065585
    MICHEL BATIGNIANI PIMENTA RODRIGUES - RA 0065525

*/
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5000
#define MBUFFER 1024

class Server {
private:
    int serverSocket;
    int clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[MBUFFER];

public:
    Server() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        memset(&serverAddress, 0, sizeof(serverAddress));

        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(PORT);
        serverAddress.sin_addr.s_addr = INADDR_ANY;
    }

    ~Server() {
        close(clientSocket);
        close(serverSocket);
    }

    void start() {
        bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        listen(serverSocket, 1);
        std::cout << "O servidor está aguardando uma mensagem..." << std::endl;

        clientSocket = accept(serverSocket, NULL, NULL);
        std::cout << "Cliente conectado" << std::endl;

        while (true) {
            memset(buffer, 0, sizeof(buffer));

            ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesRead <= 0) {
                break;
            }

            std::cout << "Mensagem recebida: " << buffer << std::endl;

            reverseString(buffer);

            std::cout << "Mensagem invertida: " << buffer << std::endl;

            if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
                perror("Falha ao enviar a mensagem para o cliente");
                break;
            }

            std::cout << "Mensagem enviada para o cliente: " << buffer << std::endl;

            if (strcmp(buffer, "\n") == 0) {
                break;
            }
        }
    }

private:
    void reverseString(char* str) {
        int Tletras = strlen(str);
        for (int i = 0, j = Tletras - 1; i < j; i++, j--) {
            char aux = str[i];
            str[i] = str[j];
            str[j] = aux;
        }
    }
};

int main() {
    Server server;
    server.start();

    return 0;
}
