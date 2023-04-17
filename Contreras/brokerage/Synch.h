//
// Created by Anthony Contreras on 4/16/23.
//

#ifndef BROKERAGE_SYNCH_H
#define BROKERAGE_SYNCH_H

#include <semaphore.h>

class Synch{
public:
    Synch(int prod_limit, int capacity, int btc_capacity);

    int reqs_produced = 0;
    int reqs_completed = 0;
    int prod_limit;
    sem_t available_slots; sem_t unconsumed;
    sem_t available_btc_slots;
    sem_t barrier;
};
#endif //BROKERAGE_SYNCH_H
