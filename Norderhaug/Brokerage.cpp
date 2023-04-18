//
// Created by Anthony Norderhaug on 4/14/23.
//

#include "Brokerage.h"

void Brokerage::createServices() {
    // Initializing consumers & producers
    this->producers = new TradeRequestService[2]{
            TradeRequestService(Bitcoin), TradeRequestService(Ethereum)};
    this->consumers= new RequestTransactionService[2]{
            RequestTransactionService(BlockchainX), RequestTransactionService(BlockchainY)};
}

Brokerage::Brokerage(int argc, char **argv) {
    createServices(); // Default service routines

    //    ./cryptoexc -r 150 -x 10 -y 15 -b 12 -e 7
    //    int prod = 150;
    //    int btc_process = 12;
    //    int eth_process = 7;
    //    int x_process = 10;
    //    int y_process = 15;

    // Parsing command-line arguments
    int option = 0;
    while ((option = getopt(argc, argv, "r:x:y:b:e:")) != -1) {
        switch (option) {
            // Production Limit
            case 'r': {
                prod_limit = atoi(optarg);
                break;
            }
            // Blockchain X processing rate
            case 'x': {
                this->consumers[BLOCKCHAIN_X_IDX].processing_time = atoi(optarg);
                break;
            }
            // Blockchain Y processing rate
            case 'y': {
                this->consumers[BLOCKCHAIN_Y_IDX].processing_time = atoi(optarg);
                break;
            }
            // Bitcoin production rate
            case 'b': {
                this->producers[BTC_IDX].processing_time = atoi(optarg);
                break;
            }
            // Ethereum production rate
            case 'e': {
                this->producers[ETH_IDX].processing_time = atoi(optarg);
                break;
            }
            case ':': {
                cout << "Option '" << optopt << "' was not given a parameter. Applying default.";
                break;
            }
            case '?': {
                cout << "Unknown argument '" << optopt << "'";
                exit(1);
            }
            default: {
                printf("Usage: ./cryptoexc -r -x -y -b -e");
                exit(1);
            }
        }
    }
}
