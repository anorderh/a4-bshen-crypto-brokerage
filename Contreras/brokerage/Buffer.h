//
// Created by Anthony Contreras on 4/16/23.
//

#ifndef BROKERAGE_BUFFER_H
#define BROKERAGE_BUFFER_H

#include <queue>
#include <pthread.h>
#include "Request.h"

using namespace std;

class Buffer{
public:
    Buffer(int capacity);

    pthread_mutex_t mutex;
    queue<Request> trade_req_queue;
    int capacity;

    void publish(Request req);
    Request retrieve();

};

#endif //BROKERAGE_BUFFER_H
