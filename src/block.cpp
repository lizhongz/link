#include "json.hpp"

#include "block.h"
#include "utils.h"


void blockchain::to_json(nlohmann::json& j, const blockchain::Block& blk) {
    j = nlohmann::json({
        {"block", blk.id},
        {"nonce", blk.nonce},
        {"prev", blk.prev},
        {"hash_code", blk.hash_code},
        {"timestamp", time_to_str(blk.timestamp)},
    });

    auto transactions = nlohmann::json::array();
    for (auto tx : blk.transactions) {
        transactions.push_back(nlohmann::json(tx));
    }
    j["transactions"] = transactions;
} 