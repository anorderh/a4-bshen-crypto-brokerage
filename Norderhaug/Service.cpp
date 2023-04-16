//
// Created by Anthony Norderhaug on 4/14/23.
//

#include "Service.h"

TradeRequestService::TradeRequestService(RequestType type) {
    this->type = type;
}

RequestTransactionService::RequestTransactionService(ConsumerType type) {
    this->type = type;
}