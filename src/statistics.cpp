
#include"statistics.hpp"
#include<iostream>

double mean(const std::vector<double>& data) {
    if (data.empty()) {
        return NAN;
    }
    double sum = 0.0;
    for (double x : data) {
        sum += x;
    }
    return sum / data.size();
}

double variance(const std::vector<double>& data, double avg) {
    if (data.size() < 2) {
        return NAN;
    }
    double diffSq = 0.0;
    for (double x : data) {
        double diff = x - avg;
        diffSq += diff * diff;
    }
    return diffSq / (data.size() - 1);
}
double empricalProbability(const std::vector<double>& data,double min_price){
    int counter=0;
    for (double i:data){
        if(i>min_price){
            counter+=1;
        }
    }
    double p=static_cast<double>(counter)/data.size();
    return p;
}
double theoriticalProbability(double threshold,double initial_price,double volatility,double drift,double time){
    double thre_init=std::log(threshold/initial_price);
    double k = (drift- (volatility*volatility)/2)*time;
    double x = (thre_init-k)/(volatility*std::sqrt(time));
    double theoriticalProbability=(0.5)*std::erfc(x/sqrt(2));
    return theoriticalProbability;
}