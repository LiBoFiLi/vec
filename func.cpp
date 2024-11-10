#include "header.h"

matrix::matrix(int Rows,int Cols){
        rows = Rows;
        cols = Cols;
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j]=0;
            }
        }
    }

    matrix::matrix(){
        rows=0;
        cols=0;
        data=nullptr;
    }

/**
    matrix::~matrix(){
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    */
    

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

    matrix& matrix::operator=(const matrix& other) {
    if (this == &other) return *this; 
    
    if (rows != other.rows || cols != other.cols) {
        cleardata(); 

        rows = other.rows;
        cols = other.cols;
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[cols];
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

    /**
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
    */

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

    void matrix::swaprows(int a, int b) {
    if (a >= rows || b >= rows) {
        throw out_of_range("Row index out of range.");
    }
    for (int i = 0; i < cols; i++) {
        swap(data[a][i], data[b][i]);
    }
    }
    void matrix::swapcols(int a, int b) {
    if (a >= cols || b >= cols) {
        throw out_of_range("Column index out of range.");
    }
    for (int i = 0; i < rows; i++) {
        swap(data[i][a], data[i][b]);
    }
}

    /**
    void matrix::swaprows(int a, int b){
        for(int i=0;i<cols;i++){
            swap(data[a][i], data[b][i]);
        }
    }
    

    void matrix::swapcols(int a, int b){
        for(int i=0;i<rows;i++){
            swap(data[i][a], data[i][b]);
        }
    }
    */

   

    pairm LUP(matrix init) {
    matrix A = init;
    if (A.getRows() != A.getCols()) throw invalid_argument("invalid matrix");
    
    int n = A.getRows();
    matrix p(1, n);  
    for (int i = 0; i < n; i++) p(0, i) = i;
    
    for (int k = 0; k < n; k++) {
      
        float max = std::abs(A(k, k));
        int k1 = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(A(i, k)) > max) {
                k1 = i;
                max = abs(A(i, k));
            }
        }

        
        if (A(k1, k) == 0) throw invalid_argument("error");

        
        if (k1 != k) {
            A.swaprows(k, k1);
           p.swapcols(k, k1);
        }

       
        for (int i = k + 1; i < n; i++) {
            A(i, k) /= A(k, k);
            for (int j = k + 1; j < n; j++) {
                A(i, j) -= A(i, k) * A(k, j);
            }
        }
    }
    pairm result(A,p);
    //result.a.print();
    //A.print();
    //p.print();
    return result;
}


    /**
    pairm LUP(matrix init){
        matrix A = init;
        if(A.getRows() != A.getCols()) throw invalid_argument("invalid matrix");
        int n = A.getCols();
        matrix p(1,n);
        for(int i = 0; i<n; i++) p(0,i) = i;
        for(int k=0; k<n; k++){
            float max = A(0,k);
            int k1=0;
            for(int i=k; i<n; k1++){
                if( (max>A(i,k) && max>-A(i,k)) || (max<A(i,k) && max<-A(i,k)) ) {
                    k1=i;
                    max=A(i,k);
                }
            }
            if(A(k1,k)==0) throw invalid_argument("invalid matrix1");
            A.swaprows(k1,k);
            p.swapcols(k1,k);
            for(int i = k+1; i<n; i++){
                A(i,k) = A(i,k)/A(k,k);
                for(int j=k+1; j<n; j++){
                    A(i,j) = A(i,j) - A(i,k)*A(k,j);
                }
            }
        }
        pairm result;
        result.a = A;
        result.p = p;
        return result;
    }
    */

   matrix le(matrix init, matrix B){
    if(B.getCols()>1 || B.getRows()!=init.getRows()) throw invalid_argument("invalid b");
    matrix A = init;
    matrix b = B;
    pairm reslup = LUP(A);
    int n = A.getRows();
    matrix P(n,n);
    for(int i=0;i<reslup.p.getCols();i++){
        P(i,reslup.p(0,i)) = 1;
    }
    matrix y(n,1);
    matrix x(n,1);
    b = P*b;
    float carry = 0;    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i-1;j++){
            carry = carry + A(i,j)*y(j,0);
        }
        y(i,0) = b(i,0) - carry;
    }
    carry = 0; 
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            carry = carry + A(i,j)*x(j,0);
        }
        x(i,0) = (1/A(i,i))*(y(i,0) - carry);
    }
    return x;
   }