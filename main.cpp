#include "func.cpp"

int main(){
    matrix m(3,1), n(3,3);
    m(0,0) = 1.5;
    m(2,0) = 2;
    m(1,0) = 3;
    n(0,0) = 2;
    n(0,1) = 2;
    n(0,2) = 3;
    n(1,0) = 4;
    n(1,1) = 5;
    n(1,2) = 6;
    n(2,0) = 7;
    n(2,1) = 8;
    n(2,2) = 9;
    m.print();
    cout<< '\n';
    n.print();
    cout<< '\n';
    matrix L = le(n, m);
    L.print();
    return 0;
}