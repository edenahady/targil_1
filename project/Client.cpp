//
// Created by edena on 12/26/2022.
//

#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int CreateClient(string ip, int port) {
    const char* ip_address = ip;
    const int port_no = port;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    while(true) {
        char data_addr[];
        getline(cin , data_addr);
        int data_len = strlen(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
        // error
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout<< "connection is closed" << endl;
        } else if (read_bytes < 0) {
            perror("error receiving to server");
        } else {
            cout << buffer;
        }
    }
    close(sock);
    return 0;
}
int main(int argc, char* argv[])
{
    string port_str = argv[2];
    string ip = argv[1];
    int port = stoi(port_str);
    if(port < 1024 or port > 65535)
    {
        cout<< "port number is not valid"
    }
}
