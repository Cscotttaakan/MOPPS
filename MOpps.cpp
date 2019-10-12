//
//  MOpps.cpp
//  MatrixOperationsLibrary
//
//  Created by Craig Scott on 10/7/19.
//  Copyright © 2019 Craig Scott. All rights reserved.
//

#include "MOpps.hpp"
//Dot product
// M_i * M_j , must be n x m * m x p so in cols of first vec must be equiv to rows of second vec

const char *InvalidDotProduct::what() const throw(){
    return "Dimensions of vectors are not the same, not valid operation";
}

const char *InvalidMatrixProduct::what() const throw(){
    return "Dimensions of matrix are not compatible";
}
