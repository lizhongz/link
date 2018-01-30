#include <string>
#include <iostream>

#include <json.hpp>
#include "crow_all.h"

#include "server.h"

void blockchain::Server::run() {

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello Crypto!";
    });

    CROW_ROUTE(app, "/blockchain") ([&]{
        nlohmann::json j = blockchain;
        return j.dump();
    });

    CROW_ROUTE(app, "/tx").methods("POST"_method) ([&](const crow::request& req){
        auto body = nlohmann::json::parse(req.body);
        blockchain.add_tx(Tx{
            body["from"].get<std::string>(),
            body["to"].get<std::string>(),
            body["amount"].get<double>()
        });

        return crow::response("Added transaction");
    });

    app.port(port).multithreaded().run();
}