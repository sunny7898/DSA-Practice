#include<iostream>
using namespace std;

int main(){
    int n, i, j, k, m;
    cin >> n >> i >> j >> k >> m;

    int onmask = (1 << i);
    int offmask = ~(1 << j);
    int tmask = (1 << k);
    int cmask = (1 << m);

    cout << (n | onmask) <<"\n";
    cout << (n & offmask) <<"\n";
    cout << (n ^ tmask) <<"\n";
    cout << ((n & cmask) ? "true\n" : "false\n");
    return 0;
}