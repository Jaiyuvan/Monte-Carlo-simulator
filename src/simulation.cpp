#include "statistics.hpp"
#include "brownian.hpp"
#include"csv_parser.hpp"
#include<iostream>
int main(){
    /*std::mt19937 engine(42);
    std::normal_distribution<double> dist(0.0,1.0);
    std::vector<double> final_prices;
    for (int i=1;i<=1000;i++){
        std::vector<double>prices=simulator(engine,dist);
        final_prices.push_back(prices.back());
    }
    for (const auto& i:final_prices){
        std::cout<<"Stock: "<<i << "\n";
    }
    double avg=mean(final_prices);
    double monteEstimation=empricalProbability(final_prices,110.0);
    double theorticalValue=theoriticalProbability(110.0,100.0,0.2,0.1,1.0);
    std::cout<<"Theoritical Value:"<<theorticalValue<<"\n";
    std::cout << "Mean : "<<avg<<"\n";
    std::cout << "Variance : "<<variance(final_prices,avg)<<"\n";
    std::cout << "Monte Carlo Estimation : "<<monteEstimation<<"\n";*/
    for (int i=0;i<3;i++){
        std::ifstream file("data/sp500.csv");
        if (!file.is_open()){
            std::cerr<<"Could not open the file";
        }
    std::vector<StockData> prices=parser(file);

    }
    
    return 0;
}