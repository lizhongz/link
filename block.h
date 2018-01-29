#pragma once

#include <vector>
#include <string>

#include "tx.h"


namespace blockchain {

class Block {
public:
    int id;
    int nonce;
    std::vector<Tx> transactions;
    std::string prev;
    std::string hash_code;

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