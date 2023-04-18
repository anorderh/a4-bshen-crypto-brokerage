//
// Created by Anthony Norderhaug on 4/16/23.
//

#ifndef NORDERHAUG_PRODUCER_H
#define NORDERHAUG_PRODUCER_H

#include "Service.h"
#include "Buffer.h"
#include "Synch.h"

class ProducerData {
public:
    ProducerData(TradeRequestService service, Buffer* buffer, Synch* synch);

    TradeRequestService service; Buffer* buffer; Synch* synch;
};

void* produce(void* arg);

#endif //NORDERHAUG_PRODUCER_H
