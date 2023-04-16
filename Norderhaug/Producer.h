//
// Created by Anthony Norderhaug on 4/16/23.
//

#ifndef NORDERHAUG_PRODUCER_H
#define NORDERHAUG_PRODUCER_H

#include "Service.h"
#include "Buffer.h"
#include "Synch.h"

void produce(TradeRequestService* service, Buffer* buffer, Synch* synch);

#endif //NORDERHAUG_PRODUCER_H
