//
// Created by Anthony Norderhaug on 4/14/23.
//
#include "Brokerage.h"
#include "Synch.h"
#include "Buffer.h"
extern "C" {
    #include "cryptoexchange.h"
}


int main(int argc, char **argv) {
    /**
     * 1. grab fields
     * 2. create threads & utilize data
     * 3. create buffer & ensure atomic & exclusive access
     * 4. introduce barrier in main
     */
    // 1. Grab fields
    Brokerage brokerage(argc, argv);

    // 2b. Create buffer w/ mutex for exclusive access & implement internal synch
    Buffer buffer(brokerage.prod_limit, brokerage.queue_limit, brokerage.btc_limit);

    // 3. Create threads utilizing data from fields


    // 4. Create barrier within main and implement into consumer threads

    // 5. Incorporate provided output methods into code
}