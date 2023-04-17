//
// Created by Anthony Contreras on 4/16/23.
//

#include "Synch.h"

Synch::Synch(int prod_limit, int capacity, int btc_capacity) {
    this->prod_limit = prod_limit;
    //initialize our semaphores
    sem_init(&this->available_slots,0,capacity);
    sem_init(&this->unconsumed, 0, 0);
    sem_init(&this->available_btc_slots, 0, btc_capacity);

    sem_init(&this->barrier, 0, 0);
}
