#pragma once

#include "blockchain.h"

namespace blockchain {

class Server {
private:
    Blockchain blockchain;
    int port = 18080;

public:
    void run();
};

}