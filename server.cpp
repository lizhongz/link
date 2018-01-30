#include "server.h"

void blockchain::Server::run() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello Crypto!";
    });

    CROW_ROUTE(app, "/blockchain") ([&]{
        return "chain"
    });

    CROW_ROUTE(app, "/tx").methods("POST"_method) ([&](const crow::request& req){
        return "Added transaction";
    });

    app.port(port).multithreaded().run();
}