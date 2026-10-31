
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
