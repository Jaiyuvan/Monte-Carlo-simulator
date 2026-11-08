#include<iostream>
#include "csv_parser.hpp"
std::vector<StockData> parser(std::ifstream& csv_file){
    std::string line={};
    std::getline(csv_file,line);
    std::vector<StockData> annual_market_data={};
    size_t proper_rows=0;
    size_t invalid_rows=0;
    size_t malformed_rows=0;
    //For splitting each line
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
                row[1],
                std::stod(row[2]),
                std::stod(row[3]),
                std::stod(row[4]),
                std::stod(row[5]),
                std::stol(row[6])
            };
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
    std::cout<<"Proper Rows: "<<proper_rows<<"\n";
    std::cout<<"Malformed Rows: "<<malformed_rows<<"\n";
    std::cout<<"Invalid Rows: "<<invalid_rows<<"\n";
    return annual_market_data;
}
