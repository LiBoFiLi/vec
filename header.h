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
    matrix();
    matrix(int Rows, int Cols);
   //~matrix();
    float& operator()(int row, int col);
    void print() const;
    matrix& operator=(const matrix& other);
    matrix operator+(const matrix& other) const;
    matrix operator-(const matrix& other) const;
    matrix operator*(const matrix& other) const;
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    float* operator()(int row) {
        return data[row];
    }
    void swaprows(int a, int b);
    void swapcols(int a, int b);
};

struct pairm{
    matrix a;
    matrix p;
    pairm(matrix c, matrix b){
        a=c;
        p=b;
        
    }

    pairm& operator=(const pairm& other) {
    if (this == &other) return *this; 
    a=other.a;
    p=other.p;
    return *this;
}
};

