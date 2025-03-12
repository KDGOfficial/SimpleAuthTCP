//Server Side
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <vector>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT "27015"
#define BUFFER_SIZE 512

using namespace std;

struct User {
    string username;
    string password;
};

vector<User> usersList;

bool addUser(const string& username, const string& password) {
    for (const auto& user : usersList)
        if (user.username == username) return false;

    usersList.push_back({ username, password });
    return true;
}

bool authenticateUser(const string& username, const string& password) {
    for (const auto& user : usersList)
        if (user.username == username && user.password == password) return true;

    return false;
}

int main() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return 1;

    addrinfo hints{}, * addrInfo = nullptr;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, PORT, &hints, &addrInfo) != 0) {
        WSACleanup();
        return 1;
    }

    SOCKET serverSock = socket(addrInfo->ai_family, addrInfo->ai_socktype, addrInfo->ai_protocol);
    if (serverSock == INVALID_SOCKET) {
        freeaddrinfo(addrInfo);
        WSACleanup();
        return 1;
    }

    if (bind(serverSock, addrInfo->ai_addr, (int)addrInfo->ai_addrlen) == SOCKET_ERROR) {
        closesocket(serverSock);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(addrInfo);

    if (listen(serverSock, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(serverSock);
        WSACleanup();
        return 1;
    }

    cout << "Server started...\n";

    while (true) {
        SOCKET clientSock = accept(serverSock, nullptr, nullptr);
        if (clientSock == INVALID_SOCKET) continue;

        char buffer[BUFFER_SIZE] = { 0 };
        recv(clientSock, buffer, BUFFER_SIZE, 0);
        string request(buffer);

        string response;
        if (request.find("register:") == 0) {
            string data = request.substr(9);
            size_t pos = data.find(':');
            if (pos != string::npos) {
                string username = data.substr(0, pos);
                string password = data.substr(pos + 1);
                response = addUser(username, password) ? "Registration successful" : "User already exists";
            }
        }
        else if (request.find("login:") == 0) {
            string data = request.substr(6);
            size_t pos = data.find(':');
            if (pos != string::npos) {
                string username = data.substr(0, pos);
                string password = data.substr(pos + 1);
                response = authenticateUser(username, password) ? "Login successful" : "Invalid credentials";
            }
        }

        send(clientSock, response.c_str(), response.size(), 0);
        closesocket(clientSock);
    }

    closesocket(serverSock);
    WSACleanup();
    return 0;
}
