#include "func.cpp"

int main(){
    matrix m(2,2), n(2,2);
    m(0,0) = 3;
    m(0,1) = 2;
    m(1,0) = 1;
    m(1,1) = 4;
    n(0,0) = 1;
    n(0,1) = 2;
    n(1,0) = 3;
    n(1,1) = 4;
    m.print();
    cout<< '\n';
    n.print();
    return 0;
}