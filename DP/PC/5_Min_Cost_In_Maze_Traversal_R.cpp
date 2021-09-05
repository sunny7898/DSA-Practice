#include<bits/stdc++.h>
using namespace std;

int getCheapestPathCost(vector<vector<int>> maze, int sr, int sc, int dr, int dc){
    
    if (sr == dr && sc == dc){
        return maze[sr][sc];
    }
    
    int costOfHpath = INT_MAX;
    int costOfVpath = INT_MAX;

    if (sc < dc) 
        costOfHpath = getCheapestPathCost(maze, sr, sc+1, dr, dc);
    if (sr < dr)
        costOfVpath = getCheapestPathCost(maze, sr+1, sc, dr, dc);

    int cost = maze[sr][sc] + min(costOfHpath, costOfVpath);
    return cost;
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

    int ans = getCheapestPathCost(maze, 0, 0, n-1, m-1);
    cout << ans;
    return 0;
}