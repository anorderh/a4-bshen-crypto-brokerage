//
// Created by Anthony Norderhaug on 4/14/23.
//

#ifndef NORDERHAUG_INTERACTION_H
#define NORDERHAUG_INTERACTION_H

struct TradeRequest {
    TradeRequest(bool isBTC=false);

    bool isBTC;
    int duration = 0;
};

struct RequestTransaction {
    int duration = 0;
};



#endif //NORDERHAUG_INTERACTION_H
