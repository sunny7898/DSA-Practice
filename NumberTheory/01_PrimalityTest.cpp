#include<iostream>
using namespace std;

bool checkPrime(int n){
    if (n == 1)
        return false;
    int cnt = 0;
    for(int i=2; i<n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int T; cin >> T;
    while(T--){
        int num; cin >> num;
        cout << num<< ": " << checkPrime(num) <<"\n";
    }
}