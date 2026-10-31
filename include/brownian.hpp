
#pragma once

#include <vector>
#include <random>
#include <cmath>

void random_number(std::vector<double>& data, int size,std::mt19937& engine,std::normal_distribution<double>& dist);

double brownian_model(
    double z,
    double volatility,
    double growth_rate,
    double time,
    double current_price
);

std::vector<double> simulator(std::mt19937& engine,std::normal_distribution<double>& dist);

