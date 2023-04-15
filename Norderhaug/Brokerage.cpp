//
// Created by Anthony Norderhaug on 4/14/23.
//

#include "Brokerage.h"

void Brokerage::createServices() {
    // Initializing consumers & producers
    this->consumers[Bitcoin] = TradeRequestService(true);
    this->consumers[Ethereum] = TradeRequestService(false);
    this->producers[BlockchainX] = RequestTransactionService();
    this->producers[BlockchainY] = RequestTransactionService();
}

Brokerage::Brokerage(int argc, char** argv) {
    createServices(); // Default service routines

    // Parsing CLI args with getopt, implement functionality later
    // ./cryptoexc -r 150 -x 10 -y 15 -b 12 -e 7
    int prod = 150;
    int btc_process = 12;
    int eth_process = 7;
    int x_process = 10;
    int y_process = 15;

    this->prod_limit = prod;
    this->consumers[Bitcoin].processing_time = btc_process;
    this->consumers[Ethereum].processing_time = eth_process;
    this->producers[BlockchainX].processing_time = x_process;
    this->producers[BlockchainY].processing_time= y_process;
}
