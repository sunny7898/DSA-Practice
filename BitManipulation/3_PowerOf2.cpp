#include<bits/stdc++.h>
using namespace std;

bool solve(int n){
    return (n && ((n & (-n)) == n));
}

int main() {
    int n; cin >> n; 
    cout << solve(n);
    return 0;
}