#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "include/zkp.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

char buffer[1024] = {0};
void send_data(int clientSocket, std::string s){
    try{
        send(clientSocket, s.c_str(), s.size() , 0);
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }
}

std::string recv_data(int socket){
    ssize_t byte_recv = recv(socket, &buffer, sizeof(buffer) - 1, 0);
    buffer[byte_recv] = '\0';
    return std::string(buffer);

}

sockaddr_in init(){
    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    return serverAddress;
}
int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress = init();
    connect(clientSocket, (struct sockaddr*)&serverAddress,
            sizeof(serverAddress));

    // sending data
    int n = 5;
    auto secret_key = Graph_zkp::gen_key(n);
    auto G0 = Graph_zkp::graph_gen(n);
    auto G1 = Graph_zkp::per_graph(secret_key, G0);


    std::string message(buffer);
    while (message != "Accept!!!\n"){
        auto sigma = Graph_zkp::gen_key(n);
        auto H = Graph_zkp::per_graph(sigma, G0);

        std::string serialize_public_key = Graph_zkp::public_key_serialize(std::make_pair(G0,G1));
        std::string serialize_H = Graph_zkp::public_key_serialize(H);
        
        send_data(clientSocket, serialize_public_key);

        send_data(clientSocket, serialize_H);
        bool choice;
        recv(clientSocket, &choice, sizeof(choice), 0);
        std::string serialize_function;
        if (choice)
            serialize_function = Graph_zkp::function_serialize(Graph_zkp::mul_key(sigma, Graph_zkp::inv(secret_key)));
        else
            serialize_function = Graph_zkp::function_serialize(sigma);

        send_data(clientSocket, serialize_function);
        message = recv_data(clientSocket);
        std::cout << message << std::endl;
    }
    if (accept) 
        puts("Accept !!!");
    else puts("Gay");
    close(clientSocket);

    return 0;
}