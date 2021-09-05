#include<bits/stdc++.h>
using namespace std;

void printDecInc(int n){
    if (n == 0){
        return;
    }

    cout << n << "\n"; 
    printDecInc(n-1);
    cout << n <<"\n";
}

int main() {
    int n; cin >> n; 
    printDecInc(n);
    return 0;
}