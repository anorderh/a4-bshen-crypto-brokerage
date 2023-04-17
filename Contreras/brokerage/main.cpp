#include <iostream>
#include "Brokerage.h"
#include "Synch.h"
#include "Buffer.h"
extern "C"{
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

    // 2a. Create synchronization obj holding relevant semaphores
    // 2b. Create buffer & implement mutex for exclusive access
    Synch synch(brokerage.prod_limit, brokerage.queue_limit,  brokerage.btc_limit);
    Buffer buffer(brokerage.queue_limit);





    return 0;
}
