#include "header.h"

matrix::matrix(int Rows,int Cols){
        rows = Rows;
        cols = Cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    matrix::~matrix(){
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    int& matrix::operator()(int row, int col){
        return data[row][col];
    }

    void matrix::print() const{
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }