//
// Created by Anthony Norderhaug on 4/15/23.
//

#include "Buffer.h"

Buffer::Buffer(int capacity) {
    pthread_mutex_init(&this->mutex, nullptr);
    this->capacity = capacity;
}

void Buffer::publish(Request req) {
    pthread_mutex_lock(&this->mutex);
    this->trade_req_queue.push(req);
    pthread_mutex_unlock(&this->mutex);
}

Request Buffer::retrieve() {
    pthread_mutex_lock(&this->mutex);

    Request req = this->trade_req_queue.front();
    this->trade_req_queue.pop();

    pthread_mutex_unlock(&this->mutex);

    return req;
}
