//
// Created by Anthony Norderhaug on 4/15/23.
//

#ifndef NORDERHAUG_BUFFER_H
#define NORDERHAUG_BUFFER_H

#include <queue>
#include <pthread.h>
#include "Request.h"

using namespace std;

class Buffer {
public:
    Buffer(int capacity);

    pthread_mutex_t mutex;
    queue<Request> trade_req_queue;
    int capacity;

    void publish(Request req);
    Request retrieve();
};


#endif //NORDERHAUG_BUFFER_H
