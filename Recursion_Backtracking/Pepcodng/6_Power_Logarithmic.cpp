#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    if (n == 0)
        return 1;
    
    int xpnb2 = powerLogarithmic(x, n/2);
    int xn = xpnb2 * xpnb2;
    if ((n & 1))
        return x * xn;
    return xn;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}