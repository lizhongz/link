#pragma once

#include "crow_all.h"

#include "blockchain.h"

namespace blockchain {

class Server {
private:
    Blockchain blockchain;
    int port = 18080;

public:
    void run() {
        crow::SimpleApp app;

        CROW_ROUTE(app, "/")([](){
            return "Hello Crypto!";
        });

        CROW_ROUTE(app, "/blockchain") ([&]{
            return nlohmann::json(blockchain).dump();
        });

        CROW_ROUTE(app, "/tx").methods("POST"_method) ([&](const crow::request& req){
            auto body = nlohmann::json::parse(req.body);
            blockchain.add_tx(Tx{
                body["from"].get<std::string>(),
                body["to"].get<std::string>(),
                body["amount"].get<double>()
            });
            return "Added transaction";
        });

        app.port(port).multithreaded().run();
    }
};

}