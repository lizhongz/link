#pragma once

#include <string>

#include <json.hpp>


namespace blockchain {

class Tx {
public:
    std::string from;
    std::string to;
    double amount;

    Tx(std::string from, std::string to, double amount)
        : from(std::move(from)), to(std::move(to)), amount(amount) {}
};

inline void to_json(nlohmann::json &j, const Tx &tx) {
    j = nlohmann::json({
        {"from", tx.from},
        {"to", tx.to},
        {"amount", tx.amount}
    });
}

}