//
// Created by Anthony Norderhaug on 4/14/23.
//

#ifndef NORDERHAUG_ARGS_H
#define NORDERHAUG_ARGS_H

#include "cryptoexchange.h"
#include "Transaction.h"

#define BUFFER_CAPACITY 16;
#define BITCOIN_CAPACITY 5;

class Brokerage {
public:
    Brokerage(int argc, char** argv);

    int prod_limit;
    int queue_limit = BUFFER_CAPACITY;
    int bitcoin_limit = BITCOIN_CAPACITY;

    TradeRequest consumers[RequestTypeN];
    RequestTransaction producers[ConsumerTypeN];

    void createServices();
};


#endif //NORDERHAUG_ARGS_H
