//
// Created by Anthony Norderhaug on 4/16/23.
//

#include "Consumer.h"
#include <unistd.h>

void consume(RequestTransactionService* service, Buffer* buffer, Synch* synch) {
    while (synch->reqs_completed < synch->prod_limit) {
        // 1. Wait for request to be added onto queue
        sem_wait(&synch->unconsumed);

        // 2. Pull request off of queue
        Request req = buffer->retrieve();

        // 3. Signal that space has been freed up
        if (req.type == Bitcoin) {
            sem_post(&synch->available_btc_slots);
        }
        sem_post(&synch->available_slots);

        // 4. Complete request & update count
        usleep(service->processing_time * MILLI_TO_MICRO);
        synch->reqs_completed++;
    }

    // 5. Unblock barrier
    // If prod limit reached & empty, refer to Piazza & office hours on how to handle this
    sem_post(&synch->barrier);
}
