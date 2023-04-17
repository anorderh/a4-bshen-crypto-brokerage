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
    pthread_t consumer_x; pthread_t consumer_y; // Consumers

    auto btc_service = TradeRequestService(Bitcoin);
    auto eth_service = TradeRequestService(Ethereum);
    auto blockchain_x = RequestTransactionService(BlockchainX);
    auto blockchain_y = RequestTransactionService(BlockchainY);

    ProducerData* btc_data = new ProducerData(btc_service,&buffer, &synch);
    ProducerData* eth_data = new ProducerData(eth_service,&buffer, &synch);
    ConsumerData* consumer_x_data = new ConsumerData(blockchain_x,&buffer, &synch);
    ConsumerData* consumer_y_data = new ConsumerData(blockchain_y,&buffer, &synch);

    // For more deterministic output: BTC -> ETH-> BLOCKCHAIN_X -> BLOCKCHAIN_Y
    pthread_create(&btc_producer, nullptr, produce, (void *) btc_data);
    pthread_create(&eth_producer, nullptr, produce, (void *) eth_data);
    pthread_create(&consumer_x, nullptr, consume, (void *) consumer_x_data);
    pthread_create(&consumer_y, nullptr, consume, (void *) consumer_y_data);

    // 4. Barrier - Blocking until 1 consumer thread completes, i.e. all produced requests consumed
    sem_wait(&synch.barrier);

    // Ending child threads
    pthread_cancel(btc_producer);
    pthread_cancel(eth_producer);
    pthread_cancel(consumer_x);
    pthread_cancel(consumer_y);

    // Log requests produced & consumption per blockchains
    unsigned int* consumer_res[] = {blockchain_x.reqs_consumed, blockchain_y.reqs_consumed};
    log_production_history(buffer.reqs_produced, consumer_res);
}