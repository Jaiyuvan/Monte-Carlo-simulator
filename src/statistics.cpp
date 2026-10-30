
#include <vector>
#include <iostream>
#include <cmath>
#include <random>

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

void random_number(std::vector<double>& data, int size) {
    std::mt19937 engine(42);
    std::normal_distribution<double> dist(0.0, 1.0);
    for (int i = 0; i < size; i++) {
        data.push_back(dist(engine));
    }
}

double brownian_model(double z,double volatility,double growth_rate,double time,double current_price){
    double brownian_factor=sqrt(time)*z*volatility;
    double drift_factor=(growth_rate-(volatility*volatility)/2)*time;
    double future_price=current_price*(std::exp(drift_factor+brownian_factor));
    return future_price;
}
std::vector<double> future_price(const std::vector<double>& data){
    std::vector<double> future_prices{100};
    
    for (int i=0;i<data.size();i++){
        double current_price=future_prices.back();
        double k=brownian_model(data[i],0.2,0.1,1.0/252.0,current_price);
        future_prices.push_back(k);
        std::cout<<k<<'\n';
    }
    return future_prices;
}

int main() {
    std::vector<double> normal_data;
    random_number(normal_data,252);
    future_price(normal_data);
    
}
