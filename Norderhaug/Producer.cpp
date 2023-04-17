//
// Created by Anthony Norderhaug on 4/16/23.
//

#include "Producer.h"
#include <unistd.h>

void produce(TradeRequestService* service, Buffer* buffer) {
    // Iterate until prod_limit reached
    while (buffer->getProductionSum() < buffer->prod_limit) {

        // 1. Produce request via sleeping
        usleep(service->processing_time * MILLI_TO_MICRO);

        // 2. Wait for available space
        if (service->type == Bitcoin) { // If bitcoin, wait for BTC slots
            sem_wait(&buffer->synch.available_btc_slots);
        }
        sem_wait(&buffer->synch.available_slots); // General slot availability

        // 3. Add onto queue
        buffer->publish(service, Request(service->type));

        // 4. Signal that request has been added & update count
        sem_post(&buffer->synch.unconsumed);
    }
}
