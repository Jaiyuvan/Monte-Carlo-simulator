#include"csv_export.hpp"

void csv_export(std::vector<double>&year_data){
    std::ofstream file("data/csv_export.csv", std::ios::app);
    for(size_t day_data=0;day_data<year_data.size();day_data++){
        file<<year_data[day_data]<<",";
    }
    file<<"\n";
    file.close();  
}