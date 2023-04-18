//
// Created by Anthony Norderhaug on 4/16/23.
//

#include "Producer.h"
#include <unistd.h>

ProducerData::ProducerData(TradeRequestService service, Buffer* buffer, Synch* synch) : service(service) {
    this->buffer = buffer;
    this->synch = synch;
}

void* produce(void* arg) {
    auto* pd = (ProducerData*) arg; // Arguments ptr

    while (true) {
        // 1. Produce request via sleeping
        usleep(pd->service.processing_time * MILLI_TO_MICRO);

        // 2. Wait for available space
        if (pd->service.type == Bitcoin) { // If bitcoin, wait for BTC slots
            sem_wait(&pd->synch->available_btc_slots);
        }
        sem_wait(&pd->synch->available_slots); // General slot availability

        // 3. Add onto queue
        // 'publish()' contains Production Limit check, capable of ending thread!
        pd->buffer->publish(&pd->service, Request(pd->service.type));

        // 4. Signal that request has been added & update count
        sem_post(&pd->synch->unconsumed);
    }
}
