#include<iostream>
using namespace  std;

template<class T1, class T2>
class Myclass {
public:
    T1 data1; 
    T2 data2;

    void display(){
        cout << this->data1 << this->data2;
    }
};

int main() {
    
    Myclass<int, char> obj;
    obj.data1 = 5;
    obj.data2 = 'c';
    obj.display();

    return 0;
}