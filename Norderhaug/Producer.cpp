//
// Created by Anthony Norderhaug on 4/16/23.
//

#include "Producer.h"
#include <unistd.h>

void produce(TradeRequestService* service, Buffer* buffer, Synch* synch) {
    // While prod_limit not reached
    while (synch->reqs_produced < synch->prod_limit) {

        // 1. Produce request via sleeping
        usleep(service->processing_time * MILLI_TO_MICRO);

        // 2. Wait for available space
        if (service->type == Bitcoin) { // If bitcoin, wait for BTC slots
            sem_wait(&synch->available_btc_slots);
        }
        sem_wait(&synch->available_slots); // General slot availability

        // 3. Add onto queue
        buffer->publish(Request(service->type));

        // 4. Signal that request has been added & update count
        sem_post(&synch->unconsumed);
        synch->reqs_produced++;
    }
}
