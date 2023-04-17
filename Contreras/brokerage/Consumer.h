//
// Created by Anthony Contreras on 4/16/23.
//

#ifndef BROKERAGE_CONSUMER_H
#define BROKERAGE_CONSUMER_H

#include "Service.h"
#include "Buffer.h"
#include "Synch.h"

void consume(RequestTransactionService* service, Buffer* buffer, Synch* synch);



#endif //BROKERAGE_CONSUMER_H
