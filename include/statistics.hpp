#pragma once
#include <vector>
#include <cmath>

double mean(const std::vector<double>& data);
double variance(const std::vector<double>& data, double avg);
std::vector<double> future_price(const std::vector<double>& data);
double empricalprobability(const std::vector<double>& data,double min_price);
double theoriticalprobability(double threshold,double initial_price,double volatility,double drift,double time);