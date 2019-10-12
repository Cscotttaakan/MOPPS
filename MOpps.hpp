//
//  MOpps.hpp
//  MatrixOperationsLibrary
//
//  Created by Craig Scott on 10/7/19.
//  Copyright © 2019 Craig Scott. All rights reserved.
//

#ifndef MOpps_hpp
#define MOpps_hpp

#include <stdio.h>
#include <exception>
#include <vector>
#include <string>
#include <initializer_list>


struct InvalidDotProduct : public std :: exception{
    const char * what () const throw ();
};

struct InvalidMatrixProduct : public std :: exception{
    const char * what () const throw ();
};

template <typename L>
struct Matrix{
public:
    size_t row = 0;
    size_t col = 0;
    bool transpose = false;
    struct subscript_result {
        L* begin = {};
        bool trans = false;
        size_t cl = 0;
        L& operator[](const std::size_t num){
            if(trans)
                return *(begin + num * cl);
            return *(begin + num);
        }
    };
    
    subscript_result operator[](const std::size_t num){
        if(transpose)
            return subscript_result{(entries.data() + num), transpose,col};
        return subscript_result{(entries.data() + num * col),transpose,col};
    }
    
    Matrix<L> &operator=(std::initializer_list<std::initializer_list<L>> v){
        row = v.size();
        col = v.begin()->size();
        entries.resize(row*col);
        for (auto it = v.begin(); it != v.end(); ++it) {
            auto const r = it - v.begin();
            
            for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
                auto const c = it2 - it->begin();
                
                entries[r * col + c] = *it2;
            }
        }
        return *this;
    }
    
    Matrix<L> operator*(Matrix<L> n){
        Matrix<L> result;
        result.entries.resize(this->r() * n.c());
        result.row = this->r();
        result.col = n.c();
        if(this->c() != n.r())
            throw InvalidMatrixProduct();
        for(size_t i = 0; i < this->r(); i++){
            for(size_t j = 0; j < n.c(); j++){
                result[i][j] = 0;
                for(size_t k = 0; k < this->c(); k++){
                    result[i][j] += ((*this)[i][k]) * n[k][j];
                }
            }
        }
        return result;
    }
    
    std::vector<L> entries;
    std::size_t r(){
        return !transpose ? row : col;
    }
    std::size_t c(){
        return !transpose ? col : row;
    }
    Matrix<L>& T(){
        transpose = !transpose;
        return *this;
    }

    
};

#endif /* MOpps_hpp */
