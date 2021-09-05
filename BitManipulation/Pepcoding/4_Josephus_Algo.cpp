#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int hp2 = 1;
    while ((hp2<<1) <= n){
        hp2 = (hp2 << 1);
    }
    
    int l = n - hp2;
    cout << (l<<1) + 1;

    return 0;
}