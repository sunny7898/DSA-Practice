#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int count = 0; 
    while(n){
        count++;
        n = (n & (n-1));
    }
    cout << count;
    return 0;
}