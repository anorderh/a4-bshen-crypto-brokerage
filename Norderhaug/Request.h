//
// Created by Anthony Norderhaug on 4/15/23.
//

#ifndef NORDERHAUG_REQUEST_H
#define NORDERHAUG_REQUEST_H

#include "cryptoexchange.h"

class Request {
public:
    Request(RequestType type);

    RequestType type;
    int idx;
};


#endif //NORDERHAUG_REQUEST_H
