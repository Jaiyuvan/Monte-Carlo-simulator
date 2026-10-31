#include "statistics.hpp"
#include "brownian.hpp"
#include<iostream>
int main(){

    for (int i=1;i<=1000;i++){
        std::vector<double>prices=simulator();
        std::cout<<"Stock :"<<i<<"\n";
        for(const auto& elment:prices){
            std::cout<<elment<<'\n';
        }
    }
}