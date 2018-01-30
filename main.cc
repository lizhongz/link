#include <iostream>
#include <bitset>
#include <sstream>

#include "tx.h"
#include "blockchain.h"
#include "server.h"

using namespace std;
using namespace blockchain;


int main() {
//    cout << "Hello Crypto" << endl;
//
//    Tx tx{"alice", "bob", 100};
//    auto j = nlohmann::json(tx);
//    cout << j.dump() << endl;
//
//    Block blk(0, "");
//    blk.timestamp = std::chrono::system_clock::now();
//    blk.transactions.push_back(tx);
//    blk.transactions.push_back(tx);
//    auto jblk = nlohmann::json(blk);
//    cout << jblk << endl;
//
//
//    Blockchain bc;
//    cout << nlohmann::json(bc) << endl;
//
//    bc.add_tx(tx);
//    cout << nlohmann::json(bc) << endl;
//
//    tx.amount = 200;
//    bc.add_tx(tx);
//    cout << nlohmann::json(bc) << endl;
//
//    tx.amount = 300;
//    bc.add_tx(tx);
//    cout << nlohmann::json(bc) << endl;
//
//    tx.amount = 400;
//    bc.add_tx(tx);
//    cout << nlohmann::json(bc) << endl;

    auto server = Server();
    server.run();

    return 0;
}