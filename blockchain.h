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
        Blockchain();

        void add_tx(Tx tx);
        std::vector<Block> get_chain() const;
        unsigned long size() const;

    private:
        void mine(Block &blk);
        bool is_valid(const std::string& hash);
    };

    void to_json(nlohmann::json& j, const Blockchain& blc);
}