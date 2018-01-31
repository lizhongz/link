#pragma once

#include <vector>
#include <string>
#include <ctime>

#include "tx.h"


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

        Block(int id, std::string prev) : id(id), prev(std::move(prev)), nonce(0) {}

        void add_tx(Tx tx) {
            transactions.push_back(std::move(tx));
        }

        unsigned long size() {
            return transactions.size();
        }
    };

    void to_json(nlohmann::json& j, const Block& blk);

}