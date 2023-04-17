//
// Created by Anthony Norderhaug on 4/14/23.
//
#include "Brokerage.h"
#include "Synch.h"
#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"
#include "Service.h"
extern "C" {
    #include "cryptoexchange.h"
}


int main(int argc, char **argv) {
    // 1. Grab fields
    Brokerage brokerage(argc, argv);

    // 2b. Create buffer w/ mutex for exclusive access
    Buffer buffer(brokerage.prod_limit);
    // 2b. Create synch obj storing semaphores
    Synch synch(brokerage.queue_limit, brokerage.btc_limit);

    // 3. Create service objs, data ptrs, & associated threads.
    pthread_t btc_producer; pthread_t eth_producer; // Producers
    pthread_t blockchain_x_consumer; pthread_t blockchain_y_consumer; // Consumers

    ProducerData* btc_data = new ProducerData(TradeRequestService(Bitcoin),
                                              &buffer, &synch);
    ProducerData* eth_data = new ProducerData(TradeRequestService(Ethereum),
                                              &buffer, &synch);
    ConsumerData* blockchain_x_data = new ConsumerData(RequestTransactionService(BlockchainX),
                                                       &buffer, &synch);
    ConsumerData* blockchain_y_data = new ConsumerData(RequestTransactionService(BlockchainY),
                                                       &buffer, &synch);

    pthread_create(&btc_producer, nullptr, produce, (void *) btc_data);
    pthread_create(&eth_producer, nullptr, produce, (void *) eth_data);
    pthread_create(&blockchain_x_consumer, nullptr, consume, (void *) blockchain_x_data);
    pthread_create(&blockchain_y_consumer, nullptr, consume, (void *) blockchain_y_data);

    // 4. Barrier - Blocking until 1 consumer thread completes. Then finishes, leaving OS to end child threads.
    sem_wait(&synch.barrier);
}