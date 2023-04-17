//
// Created by Anthony Norderhaug on 4/15/23.
//

#ifndef NORDERHAUG_BUFFER_H
#define NORDERHAUG_BUFFER_H

#include <queue>
#include <pthread.h>
#include "Request.h"
#include "Synch.h"
#include "Service.h"
#include "log.h"

using namespace std;

class Buffer {
public:
    Buffer(int prod_limit, int capacity, int btc_capacity);

    int prod_limit;
    pthread_mutex_t mutex;
    queue<Request> trade_req_queue;
    Synch synch;

    // Indices: BTC = 0, ETH = 1
    unsigned int reqs_produced[2];
    unsigned int queue_tracker[2];

    void publish(TradeRequestService* service, Request req);
    Request retrieve(RequestTransactionService* service);
    bool isEmpty();
    int getProductionSum();
};


#endif //NORDERHAUG_BUFFER_H
