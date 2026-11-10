#include<iostream>
#include "csv_parser.hpp"
#include "benchmark.hpp"
#include<charconv>
std::vector<StockData> parser(std::ifstream& csv_file){
    std::string line={};
    std::getline(csv_file,line);
    std::vector<StockData> annual_market_data={};
    size_t proper_rows=0;
    size_t invalid_rows=0;
    size_t malformed_rows=0;
    //For splitting each line
    {
    struct Timer time_taken;
    while(std::getline(csv_file,line)){     
        std::stringstream ss(line);
        std::vector<std::string>row;
        std::string data;
        try{
            //For splitting each field in CSV
            while(std::getline(ss,data,',')){
                row.push_back(data);
            }
            //check if data is missing
            if(row.size()!=7){
                malformed_rows+=1;
                continue;
            }
            StockData stockInfo={
                row[0],
                row[1]
            };
            std::from_chars(row[2].data(),row[2].data()+row[2].size(),stockInfo.open);
            std::from_chars(row[3].data(),row[3].data()+row[3].size(),stockInfo.high);
            std::from_chars(row[4].data(),row[4].data()+row[4].size(),stockInfo.low);
            std::from_chars(row[5].data(),row[5].data()+row[5].size(),stockInfo.close);
            std::from_chars(row[6].data(),row[6].data()+row[2].size(),stockInfo.volume);
            annual_market_data.push_back(stockInfo);
            proper_rows+=1;
        }
    
        catch (const std::invalid_argument&){
            invalid_rows+=1;
            continue;
        }
        catch (const std::out_of_range&){
            invalid_rows+=1;
            continue;
        }
        
    }
    }

    return annual_market_data;
}
