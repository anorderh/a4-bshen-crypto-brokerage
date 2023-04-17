//
// Created by Anthony Contreras on 4/16/23.
//

#ifndef BROKERAGE_REQUEST_H
#define BROKERAGE_REQUEST_H

#include "cryptoexchange.h"

class Request {
public:
    Request(RequestType type);

    Request type;
};

#endif //BROKERAGE_REQUEST_H
