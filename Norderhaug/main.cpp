//
// Created by Anthony Norderhaug on 4/14/23.
//
#include "Brokerage.h"
#include "Synch.h"
#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"
#include <pthread.h>
#include <semaphore.h>


int main(int argc, char **argv) {
    // 1. Grab fields
    Brokerage brokerage(argc, argv);

    // 2b. Create buffer w/ mutex for exclusive access
    Buffer buffer(brokerage.prod_limit);
    // 2b. Create synch obj storing semaphores
    Synch synch(brokerage.queue_limit, brokerage.btc_limit);

    // 3. Create data ptrs and initialize respective threads.
    pthread_t btc_producer; pthread_t eth_producer; // Producers
    pthread_t consumer_x; pthread_t consumer_y; // Consumers

    ProducerData *btc_data = new ProducerData(brokerage.producers[BTC_IDX], &buffer, &synch);
    ProducerData *eth_data = new ProducerData(brokerage.producers[ETH_IDX], &buffer, &synch);
    ConsumerData *consumer_x_data = new ConsumerData(brokerage.consumers[BLOCKCHAIN_X_IDX], &buffer,
                                                     &synch);
    ConsumerData *consumer_y_data = new ConsumerData(brokerage.consumers[BLOCKCHAIN_Y_IDX], &buffer,
                                                     &synch);

    // For more deterministic output: BTC -> ETH -> BLOCKCHAIN_X -> BLOCKCHAIN_Y
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
    unsigned int *consumer_res[] = {consumer_x_data->service.reqs_consumed,
                                    consumer_y_data->service.reqs_consumed};
    log_production_history(buffer.reqs_produced, consumer_res);
}