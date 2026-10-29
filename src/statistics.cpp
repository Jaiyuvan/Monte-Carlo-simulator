
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

int main() {
    std::vector<double> data;

    random_number(data, 10000);

    double sample_mean = mean(data);
    double sample_variance = variance(data, sample_mean);
    double sample_sd = std::sqrt(sample_variance);

    std::cout << "Sample mean: " << sample_mean << '\n';
    std::cout << "Sample variance: " << sample_variance << '\n';
    std::cout << "Sample standard deviation: " << sample_sd << '\n';
}
