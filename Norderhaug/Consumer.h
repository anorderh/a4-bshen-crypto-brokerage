//
// Created by Anthony Norderhaug on 4/16/23.
//

#ifndef NORDERHAUG_CONSUMER_H
#define NORDERHAUG_CONSUMER_H

#include "Service.h"
#include "Buffer.h"
#include "Synch.h"

void consume(RequestTransactionService* service, Buffer* buffer, Synch* synch);

#endif //NORDERHAUG_CONSUMER_H
