//
// Created by Anthony Contreras on 4/16/23.
//

#ifndef BROKERAGE_BROKERAGE_H
#define BROKERAGE_BROKERAGE_H

#include "cryptoexchange.h"
#include "Service.h"
#include <getopt.h>

#define DEFAULT_PRODUCTION_LIMIT 100
#define BUFFER_CAPACITY 16
#define BITCOIN_CAPACITY 5

#define BTC_IDX 0
#define ETH_IDX 1
#define BLOCKCHAIN_X_IDX 0
#define BLOCKCHAIN_Y_IDX 1

class Brokerage {
public:
    Brokerage(int argc, char ** argv);

    int prod_limit = DEFAULT_PRODUCTION_LIMIT;
    int queue_limit = BUFFER_CAPACITY;
    int btc_limit = BITCOIN_CAPACITY;

    TradeRequestService* consumers;
    RequestTransactionService* producers;

    void createServices();

};


#endif //BROKERAGE_BROKERAGE_H
