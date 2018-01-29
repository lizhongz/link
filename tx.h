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
        : from(from), to(to), amount(amount) {}
};

void to_json(nlohmann::json &j, const Tx &tx);

}