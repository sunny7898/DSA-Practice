#include<bits/stdc++.h>
#define MAX 1000
#define MAX_ELEMENT 50
using namespace std;

int dp[MAX][MAX_ELEMENT][MAX];

int maxXor(int arr[], int i, int j, int mask, int N){
    if(i >= N){

        if(j == 0)  
            return mask;
        else
            return 0;
    }

    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];
    

    int ans = 0;

    if (j > 0)
        ans = maxXor(arr, i+1, j-1, mask ^ arr[i], N);
    
    ans = max(ans, maxXor(arr, i+1, j, mask, N));



    return dp[i][j][mask] = ans;
}
int main() {
    memset(dp, -1, sizeof(dp));
    int N, K;
    cin >> N >> K;
    int arr[N];
    for(int i=0; i<N; i++)
        arr[i] = i+1;
     
    cout << maxXor(arr, 0, K, 0, N);
    
    return 0;
}