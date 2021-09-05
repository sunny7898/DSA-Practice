#include<iostream>
using namespace  std;

template<class T>
class Myclass {
    T data;
    public:
        Myclass(T a){
            data = a;
        }
        void display();
};

template <class T>
void Myclass<T>:: display(){
    cout << data;
}
////////////////////////////////////////////////
void func(int a) {
    cout << "I am func 1: "<< a << "\n";
}

template <class T>
void func(T a) {
    cout << "I am templatized func:  "<< a << "\n";
}

int main() {
    Myclass<int> obj(4);
    obj.display();
    
    func(4);
    return 0;
}