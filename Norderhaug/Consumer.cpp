//
// Created by Anthony Norderhaug on 4/16/23.
//

#include "Consumer.h"
#include "log.h"
#include <unistd.h>

ConsumerData::ConsumerData(RequestTransactionService service, Buffer* buffer, Synch* synch) : service(service) {
    this->buffer = buffer;
    this->synch = synch;
}

void* consume(void* arg) {
    auto* cd = (ConsumerData*) arg; // Arguments ptr

    // Iterate until all reqs have been produced AND queue is empty
    while (cd->buffer->getProductionSum() < cd->buffer->prod_limit || not cd->buffer->isEmpty()) {
        // 1. Wait for request to be added onto queue
        sem_wait(&cd->synch->unconsumed);

        // 2. Pull request off of queue
        Request req = cd->buffer->retrieve(&cd->service);

        // 3. Signal that space has been freed up
        if (req.type == Bitcoin) { // Bitcoin req, signal BTC semaphore
            sem_post(&cd->synch->available_btc_slots);
        }
        sem_post(&cd->synch->available_slots); // Signal general availability semaphore

        // 4. Complete request & update count
        usleep(cd->service.processing_time * MILLI_TO_MICRO);
    }

    // 5. Unblock barrier
    sem_post(&cd->synch->barrier);
}
