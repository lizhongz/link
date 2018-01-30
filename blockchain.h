#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "block.h"
#include "sha256.h"


namespace blockchain {

class Blockchain {
private:
    std::vector<Block> chain;
    Block curr;
    const static int blk_size = 2;
    const static int difficulty = 4;

public:
    Blockchain() : curr(0, "") {}

    void add_tx(Tx tx) {
        curr.add_tx(std::move(tx));
        if (curr.size() == blk_size) {
            auto blk = curr;
            mine(blk);
            blk.timestamp = std::chrono::system_clock::now();
            chain.push_back(blk);
            curr = Block(blk.id + 1, blk.hash_code);
        }
    }

    std::vector<Block> get_chain() const {
        return chain;
    }

    unsigned long size() const {
        return chain.size();
    }

private:
    void mine(Block &blk) {
        for (unsigned int i = 0; i < 0x7FFFFFFF; i++) {
            std::stringstream ss{""};
            ss << blk.id << "," << i << "," << blk.prev << ",[";
            for (auto tx : blk.transactions) {
                ss << "(" << tx.from << "," << tx.to << "," << tx.amount << ")";
            }
            ss << "]";

            auto hash = sha256(ss.str());
            if (is_valid(hash)) {
                std::cout << hash << std::endl;
                blk.nonce = i;
                blk.hash_code = hash;
                return;
            }
        }
    }

    bool is_valid(const std::string& hash) {
        for (int i = 0; i < difficulty; i++) {
            if (hash[i] != '0')
                return false;
        }
        return true;
    }
};

inline void to_json(nlohmann::json& j, const Blockchain& blc) {
    j = nlohmann::json::array();
    for (auto blk : blc.get_chain()) {
        j.push_back(blk);
    }
}

}