//
// Created by Anthony Norderhaug on 4/14/23.
//

#ifndef NORDERHAUG_ARGS_H
#define NORDERHAUG_ARGS_H

#include "cryptoexchange.h"
#include "Service.h"

#define DEFAULT_PRODUCTION_LIMIT 100;
#define BUFFER_CAPACITY 16;
#define BITCOIN_CAPACITY 5;

class Brokerage {
public:
    Brokerage(int argc, char** argv);

    int prod_limit = DEFAULT_PRODUCTION_LIMIT;
    int queue_limit = BUFFER_CAPACITY;
    int btc_limit = BITCOIN_CAPACITY;

    TradeRequestService* consumers;
    RequestTransactionService* producers;

    void createServices();
};


#endif //NORDERHAUG_ARGS_H
