#include <json.hpp>

#include "tx.h"

void blockchain::to_json(nlohmann::json& j, const Tx& tx) {
    j = nlohmann::json{{"from", tx.from}, {"to", tx.to}, {"amount", tx.amount}};
}
