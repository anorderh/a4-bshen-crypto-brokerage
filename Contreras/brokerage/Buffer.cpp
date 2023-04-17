//
// Created by Anthony Contreras on 4/16/23.
//

#include "Buffer.h"

Buffer::Buffer(int capacity) {
    //initialize the mutex
    pthread_mutex_init(&this->mutex, nullptr);
    this->capacity = capacity;
}

void Buffer::publish(Request req) {
    pthread_mutex_unlock(&this->mutex);
    this->trade_req_queue.push(req);
    pthread_mutex_unlock(&this->mutex);
}

Request Buffer::retrieve() {
    pthread_mutex_lock(&this->mutex);
    //grab the request object from the front of queue, then pop it from queue
    Request req = this->trade_req_queue.front();
    this->trade_req_queue.pop();

    pthread_mutex_unlock(&this->mutex);

    return req;
}