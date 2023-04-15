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
    // Implementation
    pthread_mutex_unlock(&this->mutex);
}

void Buffer::complete() {
    pthread_mutex_lock(&this->mutex);
    // Implementation
    pthread_mutex_unlock(&this->mutex);
}
