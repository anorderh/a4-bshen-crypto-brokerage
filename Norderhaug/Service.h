//
// Created by Anthony Norderhaug on 4/14/23.
//

#ifndef NORDERHAUG_INTERACTION_H
#define NORDERHAUG_INTERACTION_H

struct TradeRequestService {
    TradeRequestService(bool isBTC=false);

    bool isBTC;
    int processing_time = 0;
};

struct RequestTransactionService {
    int processing_time = 0;
};



#endif //NORDERHAUG_INTERACTION_H
