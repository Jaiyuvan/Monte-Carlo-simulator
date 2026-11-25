#include"brownian.hpp"
//Generating numbers in normal distribution
void random_number(std::vector<double>& data, int size,std::mt19937& engine,std::normal_distribution<double>& dist) {
    for (size_t i = 0; i < size; i++) {
        data.push_back(dist(engine));
    }
}
// Uses drift and volality to simulate future prices
double brownian_model(double z,double volatility,double growth_rate,double time,double current_price){
    //random shock ie the browinain motion=√time * z *volatility
    double brownian_factor=sqrt(time)*z*volatility;
    //overall drift that the asset follows over the time
    double drift_factor=(growth_rate-(volatility*volatility)/2)*time;
    double future_price=current_price*(std::exp(drift_factor+brownian_factor));
    return future_price;
}

// Used to generate different future price with current price
std::vector<double> future_price(const std::vector<double>& data){
    //right now initial price of the asset is 100
    std::vector<double> future_prices{100};
    
    for (size_t i=0;i<data.size();i++){
        double current_price=future_prices.back();
        double k=brownian_model(data[i],0.2,0.1,1.0/252.0,current_price);
        future_prices.push_back(k);
    }
    return future_prices;
}
std::vector<double> simulator(std::mt19937& engine,std::normal_distribution<double>& dist){
        std::vector<double>data;
        random_number(data,252,engine,dist);
        return future_price(data);        
}
