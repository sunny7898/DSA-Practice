#include<bits/stdc++.h>
using namespace std;

int main() {
    uint32_t n; cin >> n; 
    int count = 0;
    int mask = 1;

    while(n){
        if (n & mask != 0) // checking if the current bit is set.
            count++;
        mask = mask << 1;
        n = n >> 1;
    }
    cout <<  count;
    return 0;
}