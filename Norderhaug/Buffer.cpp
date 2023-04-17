//
// Created by Anthony Norderhaug on 4/15/23.
//

#include "Buffer.h"

Buffer::Buffer(int prod_limit) {
    pthread_mutex_init(&this->mutex, nullptr);
    this->prod_limit = prod_limit;
}

void Buffer::publish(TradeRequestService* service, Request req) {
    // Exclusive request push
    pthread_mutex_lock(&this->mutex);
    this->trade_req_queue.push(req);
    pthread_mutex_unlock(&this->mutex);

    // Updating req. counts in tracking arrays
    this->reqs_produced[req.idx]++;
    this->queue_tracker[req.idx]++;

    // Log addition
    log_request_added(service->type,
                      reqs_produced, queue_tracker);
}

Request Buffer::retrieve(RequestTransactionService* service) {
    // Exclusive request pop
    pthread_mutex_lock(&this->mutex);
    Request req = this->trade_req_queue.front();
    this->trade_req_queue.pop();
    pthread_mutex_unlock(&this->mutex);

    // Updating req. counts in tracking arrays
    service->reqs_consumed[req.idx]++;
    this->queue_tracker[req.idx]--;

    // Log removal
    log_request_removed(service->type, req.type,
                        service->reqs_consumed, queue_tracker);

    return req;
}

bool Buffer::isEmpty() {
//    pthread_mutex_lock(&this->mutex);
    bool res = this->trade_req_queue.empty();
//    pthread_mutex_unlock(&this->mutex);
    return res;
}

int Buffer::getProductionSum() {
    return this->reqs_produced[0] + this->reqs_produced[1];
}
