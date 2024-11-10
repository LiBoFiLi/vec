#include <iostream>

using namespace std;

class matrix{
    private:
    int** data;
    int rows, cols;

    public:
    matrix(int Rows, int Cols);
    ~matrix();
    int& operator()(int row, int col);
    void print() const;
    matrix operator+(const matrix& other) const;
};

