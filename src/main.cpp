#include <iostream>

#include "tx.h"
#include "block.h"
#include "blockchain.h"
#include "crow_all.h"
#include "server.h"

using namespace std;
using namespace blockchain;

int main() {
    Block blk(0, "");
    cout << blk.transactions.size() << endl;
    cout << blk.prev << endl;
    cout << blk.hash_code << endl;
    cout << blk.id << endl;


    Blockchain blc;
    cout << blc.size() << endl;
    blc.add_tx(Tx("alice", "bob", 100));
    blc.add_tx(Tx("alice", "charles", 100));
    cout << blc.size() << endl;
    blc.add_tx(Tx("alice", "bob", 100));
    blc.add_tx(Tx("alice", "charles", 100));
    blc.add_tx(Tx("alice", "bob", 100));
    cout << blc.size() << endl;
    blc.add_tx(Tx("alice", "charles", 100));

    cout << blc.size() << endl;

    auto chain = blc.get_chain();
    for (auto blk : chain) {
        cout << "block " << blk.id << ", " << blk.prev << ", " << blk.hash_code << endl;
        for (auto tx : blk.transactions) {
            cout << "   " << tx.from << ", " << tx.to << ", " << tx.amount << endl;
        }
    }

    //cout << sha256("hello") << " " << sha256("hello").size() << endl;

    auto server = Server();
    server.run();
}
