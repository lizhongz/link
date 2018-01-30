#include "blockchain.h"


blockchain::Blockchain::Blockchain() {

}

void blockchain::Blockchain::add_tx(Tx tx) {

}

std::vector<Block> blockchain::Blockchain::get_chain() const {

}

unsigned long blockchain::Blockchain::size() const {

}


void blockchain::Blockchain::mine(Block &blk) {

}

bool blockchain::Blockchain::is_valid(const std::string& hash) {

}

void blockchain::to_json(nlohmann::json& j, const Blockchain& blc) {

}