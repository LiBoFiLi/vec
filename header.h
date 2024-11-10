#include <iostream>

using namespace std;

class matrix{
    private:
    float** data;
    int rows, cols;

    public:
    void cleardata(){
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    matrix(int Rows, int Cols);
    ~matrix();
    float& operator()(int row, int col);
    void print() const;
    matrix& operator=(const matrix& other);
    matrix operator+(const matrix& other) const;
    matrix operator-(const matrix& other) const;
    matrix operator*(const matrix& other) const;
};

