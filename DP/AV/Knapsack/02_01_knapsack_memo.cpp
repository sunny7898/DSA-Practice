#include<bits/stdc++.h>
using namespace std;

int dp[102][1002];

int knapsack(int *wt, int *val, int W, int n){

    if (n == 0 || W == 0)
        return 0;
    
    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n-1] <= W)
        return dp[n][W] = max(val[n-1] + knapsack(wt, val ,W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
    else if (wt[n-1] > W)
        return dp[n][W] = knapsack(wt, val, W, n-1);
    return 0;
}

int main(){
    int n; cin >> n;
    int wt[n], val[n];
    for(int i=0; i<n; i++){
        cin >> wt[i];
        cin >> val[i]; 
    }

    int W; cin >> W;
    memset(dp, -1, sizeof(dp));

    cout << knapsack(wt, val, W, n);

}