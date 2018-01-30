#include <sstream>

#include "blockchain.h"
#include "sha256.h"


void blockchain::Blockchain::add_tx(Tx tx) {
    curr.add_tx(std::move(tx));
    if (curr.size() == blk_size) {
        auto blk = curr;
        mine(blk);
        blk.timestamp = std::chrono::system_clock::now();
        chain.push_back(blk);
        curr = Block(blk.id+1, blk.hash_code);
    }
}

vector<blockchain::Block> blockchain::Blockchain::get_chain() const {
    return chain;
}

unsigned long blockchain::Blockchain::size() const {
    return chain.size();
}

bool blockchain::Blockchain::is_valid(std::string hash) {
    for (int i = 0; i < difficulty; i++) {
        if (hash[i] != '0')
            return false;
    }
    return true;
}

void blockchain::Blockchain::mine(Block &blk) {
    auto blk_to_str = [&]() {
        std::stringstream s("");
        s << blk.id << ',' << blk.nonce << ",[";
        for (auto tx : blk.transactions) {
            s << tx.from << ',' << tx.to << ',' << tx.amount << ',';
        }
        s << ']' << blk.prev;

        return s.str();
    };

    for (int i=0; i < 0x7FFFFFFF; i++) {
        blk.nonce = i;
        std::string hash = sha256(blk_to_str());
        if (is_valid(hash)) {
            blk.hash_code = hash;
            break;
        }
    }
}

void blockchain::to_json(nlohmann::json& j, const Blockchain& bc) {
    const auto& chain = bc.get_chain();
    j = nlohmann::json();
    for (auto& blk : chain) {
        j.push_back(blk);
    }
}
