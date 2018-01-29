#pragma once

#include <vector>

#include "block.h"


namespace blockchain {

class Blockchain {
private:
    std::vector<Block> chain;
    Block curr;
    const static int blk_size = 2;
    const static int difficulty = 4;

public:
    Blockchain() : curr(0, "") {}

    void add_tx(Tx tx);

    std::vector<Block> get_chain() const;

    int size() const;

private:
    void mine(Block &blk);

    bool is_valid(std::string hash);
};

void to_json(nlohmann::json& j, const Blockchain& blc);

}