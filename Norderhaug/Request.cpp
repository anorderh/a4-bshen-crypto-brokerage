//
// Created by Anthony Norderhaug on 4/15/23.
//

#include "Request.h"

Request::Request(RequestType type) {
    this->type = type;
    this->idx = type == Bitcoin ? 0 : 1; // Converting RequestType into int
}
