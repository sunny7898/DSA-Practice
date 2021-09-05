#include<iostream>
using namespace std;

template<class T>
class Vector {
public:
    T *arr;
    int size;

    Vector(int m){
        size = m;
        arr = new T[size];
    }
    T dotProduct(Vector<T> &v){
        T d = 0;
        for(int i=0; i<size; i++ )
            d += this -> arr[i] * v.arr[i];
        return d;
    }
};

int main() {
    Vector<int> v1(3), v2(3);
    for(int i=0; i<3; i++){
        v1.arr[i] = i + 1;
        v2.arr[i] = i * 2;   
    }

    cout << v1.dotProduct(v2) <<"\n";

    Vector<float> v3(3), v4(3);
    for(int i=0; i<3; i++){
        v3.arr[i] = 1.1 * i ;
        v4.arr[i] = 1.7 * i;   
    }

    cout << v3.dotProduct(v4);

    return 0;
}