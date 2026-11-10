#pragma once
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<charconv>
#include <stdexcept>


//Struct for storing the stock data
struct StockData {
    std::string date{};
    std::string ticker{};
    double open{};
    double high{};
    double low{};
    double close{};

    long volume{};
};
std::vector<StockData> parser(std::ifstream& csv_file);
