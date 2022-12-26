//
// Created by edena on 12/25/2022.
//
include "server.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
using namespace std;
void createServer(int server_port) {
//socket creation,SOCK_STREAM is a const for TCP

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;//struct for address
    memset(&sin, 0, sizeof(sin));//reset the struct
    sin.sin_family = AF_INET;//address protocol type
    sin.sin_addr.s_addr = INADDR_ANY;//const for any address
    sin.sin_port = htons(server_port);//define the port
//binding the socket with bind command and checking if bind could be done
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {//listen to up to 5 clients at a time
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;//create a address struct for the sender
    information
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *) &client_sin,
                             &addr_len); //accept command creates a new socket for the client that
    wanted to connect.
    if (client_sock < 0) {//check if the creation of socket for client failed
        perror("error accepting client");
    }
    char buffer[4096];//create a buffer for the client
    int expected_data_len = sizeof(buffer);//the maximum length of data to
    recieve
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);//recieve
    a message from the clients socket into the buffer.
    if (read_bytes == 0) {
// connection is closed
    }
    else if (read_bytes < 0) {
// error
    }
    else {
        cout << buffer; }
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");

    }
    close(sock);
    return 0;
}
