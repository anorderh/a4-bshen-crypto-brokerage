//
// Created by Anthony Norderhaug on 4/14/23.
//

#ifndef NORDERHAUG_ARGS_H
#define NORDERHAUG_ARGS_H

#include "cryptoexchange.h"
#include "Service.h"
#include "getopt.h"
#include <iostream>

#define DEFAULT_PRODUCTION_LIMIT 100
#define BUFFER_CAPACITY 16
#define BITCOIN_CAPACITY 5

#define BTC_IDX 0
#define ETH_IDX 1
#define BLOCKCHAIN_X_IDX 0
#define BLOCKCHAIN_Y_IDX 1

using namespace std;

class Brokerage {
public:
    Brokerage(int argc, char** argv);

    int prod_limit = DEFAULT_PRODUCTION_LIMIT;
    int queue_limit = BUFFER_CAPACITY;
    int btc_limit = BITCOIN_CAPACITY;

    TradeRequestService* producers;
    RequestTransactionService* consumers;

    void createServices();
};


#endif //NORDERHAUG_ARGS_H
