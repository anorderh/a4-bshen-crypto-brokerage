//
// Created by Anthony Contreras on 4/16/23.
//

#include "Producer.h"
#include <unistd.h>

void produce(TradeRequestService* service, Buffer* buffer, Synch* synch){
    //while we have not reached production limit
    while(synch->reqs_produced < synch->prod_limit){
        //1. Produce(simulate) request by sleeping
        usleep(service->processing_time * MILLI_TO_MICRO);

        //2. Also wait for available space
        if(service->type == Bitcoin){ // wait for BTC slot to open
            sem_wait(&synch->available_btc_slots);
        }
        if(service->type == Ethereum){
            sem_wait(&synch->available_slots); //general availablity
        }

        //Add the request to the queue
        sem_post(&synch->unconsumed);
        synch->reqs_produced++;
    }
}
