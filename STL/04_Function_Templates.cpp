#include<iostream>
using namespace  std;

template<class T1, class T2>
float average(T1 a, T2 b){
    return (a+b)/2;
}

template<class T>
void swapp(T &a, T &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    cout << average(4, 5.4)<<"\n";
    
    int a = 4, b = 5;
    swapp(a, b);
    cout << a << " " << b;
    return 0;
}