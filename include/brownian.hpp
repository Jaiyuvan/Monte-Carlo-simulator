
#pragma once

#include <vector>
#include <random>
#include <cmath>

void random_number(std::vector<double>& data, int size);

double brownian_model(
    double z,
    double volatility,
    double growth_rate,
    double time,
    double current_price
);

std::vector<double> simulator();
