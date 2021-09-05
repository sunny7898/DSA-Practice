#include<bits/stdc++.h>
using namespace std;

int getCheapestPathCost(vector<vector<int>> maze){
    
    int n = maze.size();
    int m = maze[0].size();

    int dp[n][m];

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            
            if (i == n-1 && j == m-1){ // we are in last cell
                dp[i][j] = maze[i][j];
            }
            else if (i == n-1){  // we are in last row
                dp[i][j] = maze[i][j] + dp[i][j+1];
            }
            else if (j == m-1) {// we are in last column
                dp[i][j] = maze[i][j] + dp[i+1][j];          
            }
            else {
                dp[i][j] = maze[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    int ans = getCheapestPathCost(maze);
    cout << ans;
    return 0;
}