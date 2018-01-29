#pragma once

#include <vector>
#include <string>
#include <ctime>

#include "tx.h"


namespace blockchain {

class Block {
public:

    int id;
    int nonce;
    std::vector<Tx> transactions;
    std::string prev;
    std::string hash_code;
    std::chrono::system_clock::time_point timestamp;

    Block(int id, std::string prev) : id(id), prev(prev) {}

    void add_tx(Tx tx) {
        transactions.push_back(tx);
    }

    int size() {
        return transactions.size();
    }
};

void to_json(nlohmann::json& j, const Block& blk);

}