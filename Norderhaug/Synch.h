//
// Created by Anthony Norderhaug on 4/15/23.
//

#ifndef NORDERHAUG_SYNCH_H
#define NORDERHAUG_SYNCH_H

#include <semaphore.h>


class Synch {
public:
    Synch(int capacity, int btc_capacity);

    sem_t available_slots;
    sem_t available_btc_slots;
    sem_t unconsumed;
    sem_t barrier;
};


#endif //NORDERHAUG_SYNCH_H
