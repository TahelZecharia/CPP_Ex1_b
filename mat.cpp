#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "mat.hpp"

namespace ariel{

    string mat(int cols, int rows, char symbol1, char symbol2){
        
        if ( (cols % 2 == 0) || (rows % 2 == 0) ){
            
            throw invalid_argument("Mat size is always odd");
        }

        if ( (cols < 0) || (rows < 0) ){
            
            throw invalid_argument("Mat size can not be negative");
        }

        if ( symbol1 < '!' || symbol1 > '~' || symbol2 < '!' || symbol2 > '~' ){
            
            throw invalid_argument("Invalid argument of char");
        }

        // creating an empty matrix:
        vector < vector<char> > matrix(rows, vector<char>(cols));
        
        // sending matrix to "creat_mat" function that returns the matrix according to the desired print:
        matrix = creat_mat(matrix, 0, cols, rows, symbol1, symbol2);
        
        string rug;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                rug += matrix[i][j];
            }
            rug += "\n";
        }
      
        return rug;
    }

    vector < vector<char> > creat_mat(vector < vector<char> > &matrix, int round, int cols, int rows, char symbol1, char symbol2){
        // sets the current symbol:
        char symbol = (round % 2 == 0) ? symbol1 : symbol2;

        // determines the position of the current frame:
        int upper_wall = round;
        int lower_wall = rows - round - 1;
        int left_wall = round;
        int right_wall = cols - round - 1;

        //if there is only one row left to fill:    
        if (upper_wall == lower_wall){
           
            for (int j = left_wall; j <= right_wall; j++)
            {
                matrix[upper_wall][j] = symbol;
            }
            return matrix;
        }

        //if there is only one col left to fill:  
        if (left_wall == right_wall){
            for (int i = upper_wall; i <= lower_wall; i++)
            {
                matrix[i][left_wall] = symbol;
            }
            return matrix;
        }
        
        // otherwise, it fills the current frame, and continues the recursion:
        for (int j = left_wall; j <= right_wall; j++)
            {   
                matrix[upper_wall][j] = symbol;
                matrix[lower_wall][j] = symbol;
            }

        for (int i = upper_wall + 1; i < lower_wall; i++)
            {
                matrix[i][left_wall] = symbol;
                matrix[i][right_wall] = symbol;
            }
        // continues the recursion:
        return creat_mat(matrix, round + 1, cols, rows, symbol1, symbol2);

     } 

}