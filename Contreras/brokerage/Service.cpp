//
// Created by Anthony Contreras on 4/16/23.
//

#include "Service.h"

TradeRequestService::TradeRequestService(RequestType type) {
    this->type = type;
}

RequestTransactionService::RequestTransactionService(ConsumerType type) {
    this->type = type;
}