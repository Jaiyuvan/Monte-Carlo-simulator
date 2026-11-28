#include "statistics.hpp"
#include "brownian.hpp"
#include "csv_parser.hpp"
#include "csv_export.hpp"
#include "benchmark.hpp"
#include<iostream>
int main(){
    std::mt19937 engine(42);
    std::normal_distribution<double> dist(0.0,1.0);
    std::ifstream file("data/sample.csv");
    if (!file.is_open()){
            std::cerr<<"Could not open the file";
    }
    std::ofstream clearinFile("data/csv_export.csv");
    clearinFile.close();
    std::vector<StockData> open_prices=parser(file);
    struct Timer exporting_timer;
    //
    for (size_t i=0;i<open_prices.size();i++){
        std::vector<double>prices={};
        std::ofstream file("data/csv_export.csv",std::ios::app);
        file<<"Stock "<<i+1<<"\n";
        file.close();
        for (size_t j=0;j<100;j++){
            prices=simulator(engine,dist,open_prices[i].open);
            csv_export(prices);
        }    
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