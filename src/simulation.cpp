#include "statistics.hpp"
#include "brownian.hpp"
#include "csv_parser.hpp"
#include "csv_export.hpp"
#include<iostream>
int main(){
    std::mt19937 engine(42);
    std::normal_distribution<double> dist(0.0,1.0);
    std::ifstream file("data/sample.csv");
    if (!file.is_open()){
            std::cerr<<"Could not open the file";
    }
    std::vector<StockData> open_prices=parser(file);
    for (size_t i=0;i<open_prices.size();i++){
        std::vector<double>prices={};
        for (size_t j=0;j<10000;j++){
            prices=simulator(engine,dist,open_prices[i].open);
        }
        csv_export(prices);    
}

    /*double avg=mean(final_prices);
    double monteEstimation=empricalProbability(final_prices,110.0);
    double theorticalValue=theoriticalProbability(110.0,100.0,0.2,0.1,1.0);
    std::cout<<"Theoritical Value:"<<theorticalValue<<"\n";
    std::cout << "Mean : "<<avg<<"\n";
    std::cout << "Variance : "<<variance(final_prices,avg)<<"\n";
    std::cout << "Monte Carlo Estimation : "<<monteEstimation<<"\n";*/

    return 0;
}