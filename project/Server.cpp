//
// Created by edena on 12/25/2022.
//
#include "Server.h"
#include "KNN.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;
int CreateServer(int server_port, string file) {
    while(true) {
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
                                 &addr_len); //accept command creates a new socket for the client that wanted to connect
        if (client_sock < 0) {//check if the creation of socket for client failed
            perror("error accepting client");
        }
        char buffer[4096];//create a buffer for the client
        int expected_data_len = sizeof(buffer);//the maximum length of data to
        recieve
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);//recieve a message from the clients socket into the buffer
        if (read_bytes == 0) {
            perror("connection is closed");
        } else if (read_bytes < 0) {
            perror("error receiving from client");
        } else {
            string classification = KNN.Check_Input(buffer, file)
            // recieve back a classification or invalid
            // send back to client
        }
        int sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");

        }
    }
    close(sock);
    return 0;
}
int main(int argc, char* argv[])
{
    string port_str = argv[2];
    string file = argv[1];
    int port = stoi(port_str);
    if(port < 1024 or port > 65535)
    {
        cout<< "port number is not valid"
    }
    int rec = CreateServer(port, file)
}
