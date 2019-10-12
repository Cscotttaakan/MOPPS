//
//  main.cpp
//  MatrixOperationsLibrary
//
//  Created by Craig Scott on 10/7/19.
//  Copyright © 2019 Craig Scott. All rights reserved.
//
#include "MOpps.hpp"
#include <iostream>
#include <typeinfo>
#include<iomanip>

template <class T>
void printMatrix(T m){
    for(size_t i = 0; i < m.r(); i++){
        for(size_t j = 0; j < m.c(); j++){
            std::cout << std::setw(3) << "|";
            std::cout << std::setw(3) << m[i][j];
            std::cout << std::setw(3) << "|";
        }
        std::cout << "" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    Matrix<int> m = {};
    Matrix<int> n = {};
    m = {{-1,0}};
    n = {{1,0}};
    
    //n.T();
    //printMatrix(n);
    printMatrix(m * n.T());
    //m.T();
    return 0;
}


