#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "mat.hpp"

const int LOWEST_CHAR = 33;
const int HEIGHEST_CHAR = 126;
using namespace std;
namespace ariel{
    string mat(int length, int height, char sign1, char sign2) {

        if(sign1 < LOWEST_CHAR || sign1 > HEIGHEST_CHAR || sign2 < LOWEST_CHAR || sign2 > HEIGHEST_CHAR){
            throw runtime_error("The char u picked is not printable!");}
        if(length%2 == 0 || height%2 == 0){throw runtime_error("Mat size is always odd");}
        if(length <= 0 || height <= 0){throw runtime_error("Mat size is always positive");}
        string ans;
        if (length == 1){
            for (size_t i = 0; i < height; i++){
                ans += sign1;
            }
            return ans;
        }
        vector<vector<char>> matrix(height,vector<char>(length));
        // How many spiralas
        for (size_t i = 0; i < (height/2 +1); i++){
            char sign = sign1;
            if (i%2 != 0){sign = sign2;}
            // Adding the edges 2 rows & 2 col
            for (size_t k = i; k < length-i; k++){
                matrix[i][k] = sign;
                matrix[height - i - 1][k] = sign;
            }
            for (size_t k = i; k < height-i; k++){
                matrix[k][i] = sign;
                matrix[k][length - i - 1] = sign;
            }
        }
        // Construct a string from the data
        for (size_t i = 0; i < height; i++){
            for (size_t j = 0; j < length; j++){
                ans += matrix[i][j];
            }
            if(i != height -1){ans+= '\n';}
        }
        return ans;
    }
}