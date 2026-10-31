#include "statistics.hpp"
#include "brownian.hpp"
#include<iostream>
int main(){
    std::mt19937 engine(60);
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
    std::cout << "Mean : "<<avg<<"\n";
    std::cout << "Variance : "<<variance(final_prices,avg)<<"\n";
}