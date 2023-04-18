//
// Created by Anthony Norderhaug on 4/15/23.
//

#include "Synch.h"

Synch::Synch(int capacity, int btc_capacity) {
    sem_init(&this->available_slots, 0, capacity);
    sem_init(&this->unconsumed, 0, 0);
    sem_init(&this->available_btc_slots, 0, btc_capacity);

    sem_init(&this->barrier, 0, 0);
}
