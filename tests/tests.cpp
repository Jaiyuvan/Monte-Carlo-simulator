#include<iostream>
#include<cassert>
#include"statistics.hpp"
#include<vector>
#include<cmath>

int main(){
    std::vector<double> data={2,4,6};
    std::vector<double> empty_data{};
    std::vector<double> single_data{2};
    assert(mean(data)==4.0);
    assert(std::isnan(mean(empty_data)));
    assert(mean(single_data)==single_data[0]);
    assert(std::isnan(variance(single_data,2.0)));
    assert(variance(data,4.0)==4.0);
    std::cout<<"All test cases passed";
    return 0;
}