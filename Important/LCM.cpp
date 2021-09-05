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
    
    for(int i=0; i<N; i++) {   
        cin >> arr[i];
    }
    int den = findGCD(arr[0], arr[N-1]);
    int lcm = (arr[0] * arr[N-1])/den;

    cout << lcm;
    /*for two numbers : 
        lcm (a,b) = (a * b)/gcd(a, b)
   
        But fot more then 2 numbers; 
        lcm (a0, a1, a2 .....) = lcm (a0, an-1) = (a0*an-1)/gcd(a0, an-1)
    */

    return 0;
}