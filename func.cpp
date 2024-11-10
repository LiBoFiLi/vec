#include "header.h"

matrix::matrix(int Rows,int Cols){
        rows = Rows;
        cols = Cols;
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[cols];
        }
    }

    matrix::~matrix(){
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    float& matrix::operator()(int row, int col){
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

    matrix& matrix::operator=(const matrix& other){
        if(rows != other.rows || cols != other.cols){
        cols = other.cols;
        rows = other.rows;
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[cols];
        }
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    matrix matrix::operator+(const matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            //cout<<"error"<<'\n';
            throw invalid_argument("error");
            //return *this;
        }

        matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        /**
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << result.data[i][j] << " ";
            }
            cout << endl;
        }
        */
        return result;
    }

    matrix matrix::operator-(const matrix& other) const{
        if (rows != other.rows || cols != other.cols) {
            //cout<<"error"<<'\n';
            throw invalid_argument("error");
            //return *this;
        }

        matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result(i, j) = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    
    matrix matrix::operator*(const matrix& other) const{
        if (cols != other.rows) {
            throw invalid_argument("cols!=rows");
        }
        matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result(i, j) = 0;
                for (int k = 0; k < cols; k++) {
                    result(i, j) = result(i, j) + data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }