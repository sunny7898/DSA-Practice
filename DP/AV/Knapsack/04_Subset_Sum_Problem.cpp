#include<bits/stdc++.h>
using namespace std;


bool checkSubsetExist(int *arr, int n, int k){
    
    bool dp[n+1][k+1];
    for(int j=0; j<=k; j++){
            dp[0][j] = false;  
    }
    for(int i=0; i<=n; i++){
        if (j==0)
            dp[i][0] = true;  
        }
    }

    


    return dp[n][k];
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    
    int k; cin >> k;
    cout << checkSubsetExist(arr, n, k);
}
