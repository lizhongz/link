#pragma once

#include <vector>
#include <string>
#include <ctime>

#include "tx.h"
#include "utils.h"


namespace blockchain {

using namespace std::chrono;

class Block {
public:

    int id;
    int nonce;
    std::vector<Tx> transactions;
    std::string prev;
    std::string hash_code;
    system_clock::time_point timestamp;

    Block(int id, std::string prev)
        : id(id), prev(std::move(prev)), nonce(0) {}

    void add_tx(Tx tx) {
        transactions.push_back(std::move(tx));
    }

    unsigned long size() {
        return transactions.size();
    }
};

inline void to_json(nlohmann::json& j, const Block& blk) {
    j = nlohmann::json();
    j["id"] = blk.id;
    j["nonce"] = blk.nonce;
    j["prev"] = blk.prev;
    j["hash_code"] = blk.hash_code;
    j["timestamp"] = time_to_str(blk.timestamp);
    j["transactions"] = nlohmann::json::array();

    for (auto tx : blk.transactions) {
        j["transactions"].push_back(tx);
    }
}

}