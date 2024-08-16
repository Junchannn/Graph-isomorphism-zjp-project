#include "include/zkp.hpp"
#include <algorithm>

// Initialize static member variables
std::random_device Graph_zkp::rd;
std::mt19937 Graph_zkp::gen(Graph_zkp::rd());
std::uniform_int_distribution<> Graph_zkp::dis(0, 1);

std::vector<std::vector<bool>> Graph_zkp::graph_gen(int n) {
    std::vector<std::vector<bool>> adj_matrix(n, std::vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            adj_matrix[i][j] = dis(gen);
            adj_matrix[j][i] = adj_matrix[i][j];  
        }
    }
    return adj_matrix;
}

std::vector<int> Graph_zkp::gen_key(int n) {
    std::vector<int> key(n);
    for (int i = 0; i < n; i++)
        key[i] = i;
    std::shuffle(key.begin(), key.end(), gen);
    return key;
}

std::vector<int> Graph_zkp::inv(const std::vector<int>& key) {
    std::vector<int> inv_key(key.size());
    for (int i = 0; i < key.size(); i++) {
        inv_key[key[i]] = i;
    }
    return inv_key;
}

std::vector<std::vector<bool>> Graph_zkp::per_graph(const std::vector<int>& per, const std::vector<std::vector<bool>>& g) {
    int n = per.size();
    std::vector<std::vector<bool>> g_(n, std::vector<bool>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (g[i][j]){
                g_[per[i]][per[j]] = true;
            }
        }
    }
    return g_;
}

std::string Graph_zkp::public_key_serialize(const std::pair<std::vector<std::vector<bool>>, std::vector<std::vector<bool>>>& g) {
    json j;
    j["G0"] = g.first;
    j["G1"] = g.second;
    return j.dump(4);
}

std::string Graph_zkp::public_key_serialize(const std::vector<std::vector<bool>>& H) {
    json j;
    j["H"] = H;
    return j.dump(4);
}

std::pair<std::vector<std::vector<bool>>, std::vector<std::vector<bool>>> Graph_zkp::public_key_deserialize(const json& G) {
    std::vector<std::vector<bool>> G0 = G.at("G0").get<std::vector<std::vector<bool>>>();
    std::vector<std::vector<bool>> G1 = G.at("G1").get<std::vector<std::vector<bool>>>();
    return std::make_pair(G0, G1);
}

std::vector<std::vector<bool>> Graph_zkp::graph_deserialize(const json& G) {
    std::vector<std::vector<bool>> H = G.at("H").get<std::vector<std::vector<bool>>>();
    return H;
}
std::vector<int> Graph_zkp::mul_key(const std::vector<int>& key1, const std::vector<int>& key2) {
    std::vector<int> new_key(key1.size());
    for (int i = 0; i < key1.size(); i++) {
        new_key[i] = key2[key1[i]];
    }
    return new_key;
}

std::string Graph_zkp::function_serialize(const std::vector<int>& func) {
    json j;
    j["func"] = func;
    return j.dump(4);
}

std::vector<int> Graph_zkp::function_deserialize(const json& func) {
    return func.at("func").get<std::vector<int>>();
}
