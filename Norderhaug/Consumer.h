//
// Created by Anthony Norderhaug on 4/16/23.
//

#ifndef NORDERHAUG_CONSUMER_H
#define NORDERHAUG_CONSUMER_H

#include "Service.h"
#include "Buffer.h"
#include "Synch.h"
#include "log.h"

class ConsumerData {
public:
    ConsumerData(RequestTransactionService service, Buffer* buffer, Synch* synch);

    RequestTransactionService service; Buffer* buffer; Synch* synch;
};

void* consume(void* arg);

#endif //NORDERHAUG_CONSUMER_H
