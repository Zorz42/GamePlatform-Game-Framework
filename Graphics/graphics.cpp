//
//  graphics.cpp
//  GamePlatform-Game-Template
//
//  Created by Jakob Zorz on 28/10/2020.
//

#include "graphics.h"
#include <iostream>
#include <arpa/inet.h>

#define PORT 5732

int sock = 0;//, valread;
struct sockaddr_in serv_addr;
//char *hello = "Hello from client";
//char buffer[1024] = {0};

void send_sock(std::string data) {
    send(sock, data.c_str(), data.length(), 0);
}

int main() {
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket creation error!" << std::endl;
        return 1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        std::cout << "Invalid address/ Address not supported!" << std::endl;
        return 1;
    }
   
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connectin failed! Is GamePlatform running?" << std::endl;
        return 1;
    }
    
    send_sock("test");
    
    init();
    while(true)
        loop();
}
