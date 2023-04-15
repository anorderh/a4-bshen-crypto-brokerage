//
// Created by Anthony Norderhaug on 4/14/23.
//

#include "Brokerage.h"

void Brokerage::createServices() {
    // Initializing consumers & producers
    this->consumers[Bitcoin] = TradeRequest(true);
    this->consumers[Ethereum] = TradeRequest(false);
    this->producers[BlockchainX] = RequestTransaction();
    this->producers[BlockchainY] = RequestTransaction();
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
    this->consumers[Bitcoin].duration = btc_process;
    this->consumers[Ethereum].duration = eth_process;
    this->producers[BlockchainX].duration = x_process;
    this->producers[BlockchainY].duration = y_process;
}
