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
    Buffer(int capacity);

    queue<Request> trade_req_queue;
    int capacity;
    pthread_mutex_t mutex;

    void publish(Request req);
    void complete();
};


#endif //NORDERHAUG_BUFFER_H
