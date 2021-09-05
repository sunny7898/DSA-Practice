#include<bits/stdc++.h>
using namespace std;

int findGCD(int a, int b){
    while (a!=0){
        int rem = b % a;
        b = a;
        a = rem;
    }
    return b;
}

int main() {
    int N; cin >> N;
    int arr[N];
    int gcd = arr[0];
    for(int i=1; i<N; i++) {   
        cin >> arr[i];
        gcd = findGCD(gcd, arr[i]);      
    }
    cout << gcd;
    return 0;
}