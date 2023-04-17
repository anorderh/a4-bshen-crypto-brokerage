//
// Created by Anthony Contreras on 4/16/23.
//

#ifndef BROKERAGE_SERVICE_H
#define BROKERAGE_SERVICE_H

#include "cryptoexchange.h"

#define MILLI_TO_MICRO 1000

struct TradeRequestService{
    TradeRequestService(RequestType type);

    RequestType type;
    int processing_time = 0;
};

struct RequestTransactionService{
    RequestTransactionService(ConsumerType type);

    ConsumerType  type;
    int processing_time = 0;
};

#endif //BROKERAGE_SERVICE_H
