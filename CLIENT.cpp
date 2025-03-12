//Client Side
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT "27015"
#define BUFFER_SIZE 512

using namespace std;

bool sendToServer(const string& message, string& serverResponse) {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) return false;

    addrinfo hints{}, * addrInfo = nullptr;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo("127.0.0.1", PORT, &hints, &addrInfo) != 0) {
        WSACleanup();
        return false;
    }

    SOCKET sock = socket(addrInfo->ai_family, addrInfo->ai_socktype, addrInfo->ai_protocol);
    if (sock == INVALID_SOCKET) {
        freeaddrinfo(addrInfo);
        WSACleanup();
        return false;
    }

    if (connect(sock, addrInfo->ai_addr, (int)addrInfo->ai_addrlen) == SOCKET_ERROR) {
        closesocket(sock);
        freeaddrinfo(addrInfo);
        WSACleanup();
        return false;
    }

    send(sock, message.c_str(), message.size(), 0);

    char buffer[BUFFER_SIZE] = { 0 };
    recv(sock, buffer, BUFFER_SIZE, 0);
    serverResponse = buffer;

    closesocket(sock);
    WSACleanup();
    return true;
}

void registerUser() {
    string username, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> pass;

    string reply;
    if (sendToServer("register:" + username + ":" + pass, reply))
        cout << reply << endl;
    else
        cout << "Connection error!\n";
}

void loginUser() {
    string username, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> pass;

    string reply;
    if (sendToServer("login:" + username + ":" + pass, reply))
        cout << reply << endl;
    else
        cout << "Connection error!\n";
}

int main() {
    int option;
    while (true) {
        cout << "\n1 - Login\n2 - Register\n3 - Exit\nSelect: ";
        cin >> option;
        switch (option) {
        case 1: loginUser(); break;
        case 2: registerUser(); break;
        case 3: return 0;
        default: cout << "Invalid option\n";
        }
    }
}
