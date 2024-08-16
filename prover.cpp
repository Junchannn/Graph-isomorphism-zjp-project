// C++ program to show the example of server application in
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "include/zkp.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

char buffer[1024];
sockaddr_in init(){
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    return serverAddress;
}


std::string recv_data(int socket){
    ssize_t byte_recv = recv(socket, &buffer, sizeof(buffer) - 1, 0);
    buffer[byte_recv] = '\0';
    return std::string(buffer);

}
int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress = init();

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, 5);

    int clientSocket = accept(serverSocket, nullptr, nullptr);

    auto public_key = Graph_zkp::public_key_deserialize(json::parse(recv_data(clientSocket)));
    auto G0 = public_key.first;
    auto G1 = public_key.second;
    for (int round = 0; round < 32; round++){
        auto H = Graph_zkp::graph_deserialize(json::parse(recv_data(clientSocket)));
        int choice = Graph_zkp::dis(Graph_zkp::gen);

        send(clientSocket, &choice, sizeof(choice), 0);

        std::string s = recv_data(clientSocket);
        auto func = Graph_zkp::function_deserialize(json::parse(s));

        bool accept = 1;
        if (choice)
            accept = (H == Graph_zkp::per_graph(func, G1));
        else accept = (H == Graph_zkp::per_graph(func, G0));

        if (!accept){
            std::string reject = "Malicious connection\n";
            send(clientSocket, reject.c_str(), sizeof(reject), 0);
            close(serverSocket);
        }

        std::string message = "Round " + char(round);
        send(clientSocket, message.c_str(), sizeof(message), 0);
    }

    send(clientSocket, "Accept!!!\n", sizeof("Accept!!!\n"), 0);
    return 0;
}
