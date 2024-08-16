#ifndef ZKP_HPP
#define ZKP_HPP

#include <vector>
#include <random>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Graph_zkp {
public:
    static std::vector<std::vector<bool>> graph_gen(int n);
    static std::vector<int> gen_key(int n);
    static std::vector<int> inv(const std::vector<int>& key);
    static std::vector<std::vector<bool>> per_graph(const std::vector<int>& per, const std::vector<std::vector<bool>>& g);
    static std::string public_key_serialize(const std::pair<std::vector<std::vector<bool>>, std::vector<std::vector<bool>>>& g);
    static std::string public_key_serialize(const std::vector<std::vector<bool>>& H);
    static std::pair<std::vector<std::vector<bool>>, std::vector<std::vector<bool>>> public_key_deserialize(const json& G); // Explicit return type
    static std::vector<int> mul_key(const std::vector<int>& key1,const std::vector<int>& key2);
    static std::string function_serialize(const std::vector<int>& func);
    static std::vector<int> function_deserialize(const json& func);
    static std::vector<std::vector<bool>> graph_deserialize(const json& G);
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dis;
};

#endif // ZKP_HPP
