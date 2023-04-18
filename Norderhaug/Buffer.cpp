//
// Created by Anthony Norderhaug on 4/15/23.
//

#include "Buffer.h"

Buffer::Buffer(int prod_limit) {
    pthread_mutex_init(&this->mutex, nullptr);
    this->prod_limit = prod_limit;
}

void Buffer::publish(TradeRequestService* service, Request req) {
    pthread_mutex_lock(&this->mutex); // START of Critical Section

    // Check if prod. limit reached
    if (getProductionSum() >= prod_limit) { // Exit thread!
        pthread_mutex_unlock(&this->mutex);
        pthread_exit(nullptr);
    }

    // Push request onto queue
    this->trade_req_queue.push(req);

    // Update values tracking reqs produced & reqs in queue
    this->reqs_produced[req.idx]++;
    this->queue_tracker[req.idx]++;

    // Log addition
    log_request_added(service->type,
                      reqs_produced, queue_tracker);

    pthread_mutex_unlock(&this->mutex); // END of Critical Section
}

Request Buffer::retrieve(RequestTransactionService* service, sem_t* barrier) {
    pthread_mutex_lock(&this->mutex); // START of Critical Section

    // Pull request from queue
    Request req = this->trade_req_queue.front();
    this->trade_req_queue.pop();

    // Update values tracking reqs consumed & reqs in queue
    service->reqs_consumed[req.idx]++;
    this->queue_tracker[req.idx]--;

    // Log removal
    log_request_removed(service->type, req.type,
                            service->reqs_consumed, queue_tracker);

    // Check if prod. limit reached AND queue empty
    if (getProductionSum() >= prod_limit && isEmpty()) { // Signal barrier and exit thread!
        pthread_mutex_unlock(&this->mutex);
        sem_post(barrier);
        pthread_exit(nullptr);
    }

    pthread_mutex_unlock(&this->mutex); // END of Critical Section

    return req;
}

bool Buffer::isEmpty() {
    return this->trade_req_queue.empty();
}

int Buffer::getProductionSum() {
    return this->reqs_produced[0] + this->reqs_produced[1];
}
