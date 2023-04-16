//
// Created by Anthony Norderhaug on 4/14/23.
//

#include "Brokerage.h"

void Brokerage::createServices() {
    // Initializing consumers & producers
    this->consumers = new TradeRequestService[2]{
            TradeRequestService(Bitcoin), TradeRequestService(Ethereum)};
    this->producers = new RequestTransactionService[2]{
            RequestTransactionService(BlockchainX), RequestTransactionService(BlockchainY)};
}

Brokerage::Brokerage(int argc, char **argv) {
    createServices(); // Default service routines

    // Parsing CLI args with getopt, implement functionality later
    // ./cryptoexc -r 150 -x 10 -y 15 -b 12 -e 7
    int prod = 150;
    int btc_process = 12;
    int eth_process = 7;
    int x_process = 10;
    int y_process = 15;

    this->prod_limit = prod;
    this->consumers[BTC_IDX].processing_time = btc_process;
    this->consumers[ETH_IDX].processing_time = eth_process;
    this->producers[BLOCKCHAIN_X_IDX].processing_time = x_process;
    this->producers[BLOCKCHAIN_Y_IDX].processing_time = y_process;
}
