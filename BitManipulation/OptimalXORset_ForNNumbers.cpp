#include <bits/stdc++.h>
using namespace std;
 
// To return max xor sum of 1 to N
// using at most k numbers
int maxXorSum(int N, int K) {
 
        
    // If k is 1 then maximum possible sum is N
    if (K == 1)
        return N;
 
    // Finding number greater than or equal to N with most significantbit same as N. For example, if N is 4 result is 7. If N is 5 or 6, result is 7
    int res = 1;
    while (res <= N){
        cout << res<<" ";
        res <<= 1;
    }
 
    // Return res - 1 which denotes  a number with all bits set to 1
    return res - 1;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << maxXorSum(N,K);
    
    return 0;
}