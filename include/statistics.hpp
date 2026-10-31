#pragma once
#include <vector>
#include <cmath>

double mean(const std::vector<double>& data);
double variance(const std::vector<double>& data, double avg);
std::vector<double> future_price(const std::vector<double>& data);
