#include "func.cpp"

int main(){
    matrix m(2,2), n(2,2);
    m(0,0) = 1.5;
    m(0,1) = 2;
    m(1,0) = 3;
    m(1,1) = 4;
    n(0,0) = 5;
    n(0,1) = 6;
    n(1,0) = 7;
    n(1,1) = 8;
    m.print();
    cout<< '\n';
    n.print();
    n=m;
    cout<< '\n';
    n = m * n;
    n.print();
    return 0;
}