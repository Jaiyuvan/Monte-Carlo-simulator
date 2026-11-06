#include<iostream>
#include<cassert>
#include"statistics.hpp"
#include"brownian.hpp"
#include<vector>
#include<cmath>

int main(){
    std::vector<double> data={2,4,6};
    std::vector<double> empty_data{};
    std::vector<double> single_data{2};
    std::vector<double> prices{90, 100, 110, 120};
    double result=theoriticalProbability(110.0, 100.0, 0.2, 0.1, 1.0);
    assert(mean(data)==4.0);
    assert(std::isnan(mean(empty_data)));
    assert(mean(single_data)==single_data[0]);
    assert(std::isnan(variance(single_data,2.0)));
    assert(variance(data,4.0)==4.0);
    assert(std::isnan(variance({},0)));
    assert(empricalProbability(prices, 100.0) == 0.5);
    assert(std::abs(result-0.4695)<0.001);
    
    double bcheck=brownian_model(0.0,0.2,0.1,1/252.0,100);
    double expected=100*std::exp(0.08);
    assert((bcheck-expected)<1e-9);
    std::cout<<"All test cases passed";
    return 0;
}