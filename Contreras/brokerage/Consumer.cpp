//
// Created by Anthony Contreras on 4/16/23.
//

#include "Consumer.h"

#include <unistd.h>

void consume(RequestTransactionService* service, Buffer* buffer, Synch* synch){
    //while we haven't gone over our production limit
    while(synch->reqs_completed < synch->prod_limit){
        // 1. Wait for request to be added onto queue
        sem_wait(&synch->unconsumed);

        //2. Pull request off the queue
        Request req = buffer->retrieve();

        //3. Signal that space has been freed up, and handle if type was bitcoin
        if(req.type == Bitcoin){
            sem_post(&synch->available_btc_slots);
        }
        sem_post(&synch->available_slots);

        //4. Finish the request (sleep) & update the count
        usleep(service->processing_time * MILLI_TO_MICRO);
        synch->reqs_completed++;

        //5. Unlock the barrier
        //if prod limit reached and is empty, gotta check piazza
        sem_post(&synch->barrier);
    }
}
