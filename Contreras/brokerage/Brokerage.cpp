//
// Created by Anthony Contreras on 4/16/23.
//

#include "Brokerage.h"
#include <getopt.h>
#include <unistd.h>
#include <cstdlib>


void Brokerage::createServices() {
    //initialize producers and consumers
    this->consumers = new TradeRequestService[2]{
            TradeRequestService(Bitcoin), TradeRequestService(Ethereum)
    };
    this->producers = new RequestTransactionService[2]{
            RequestTransactionService(BlockchainX), RequestTransactionService(BlockchainY)
    };
}

    Brokerage::Brokerage(int argc, char **argv){
    //default service routine
        createServices();

        // Parsing CLI args with getopt, implement functionality later
        // ./cryptoexc -r 150 -x 10 -y 15 -b 12 -e 7

        //all process time will default to 0
        //if not defined in optargs
        int prod = 100;
        int btc_process = 0;
        int eth_process = 0;
        int x_process = 0;
        int y_process = 0;

        int option;
        while((option = getopt(argc, argv, "r:x:y:b:e:")) != -1){
           switch(option){
               case 'r':
                   prod = atoi(optarg);
                   break;
               case 'x':
                  x_process = atoi(optarg);
                  break;
               case 'y':
                   y_process = atoi(optarg);
                   break;
               case 'b':
                   btc_process = atoi(optarg);
               case 'e':
                   eth_process = atoi(optarg);

           }

        }



        this->prod_limit = prod;
        this->consumers[BTC_IDX].processing_time = btc_process;
        this->consumers[ETH_IDX].processing_time = eth_process;
        this->producers[BLOCKCHAIN_X_IDX].processing_time = x_process;
        this->producers[BLOCKCHAIN_Y_IDX].processing_time = y_process;

    }

