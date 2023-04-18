//
// Created by Anthony Norderhaug on 4/14/23.
//

#ifndef NORDERHAUG_INTERACTION_H
#define NORDERHAUG_INTERACTION_H

#include "cryptoexchange.h"

#define MILLI_TO_MICRO 1000

struct TradeRequestService {
    TradeRequestService(RequestType type);

    RequestType type;
    int processing_time = 0;
};

struct RequestTransactionService {
    RequestTransactionService(ConsumerType type);

    ConsumerType type;
    int processing_time = 0;

    // Indices: BTC = 0, ETH = 1
    unsigned int reqs_consumed[2] = {0};;
};



#endif //NORDERHAUG_INTERACTION_H
