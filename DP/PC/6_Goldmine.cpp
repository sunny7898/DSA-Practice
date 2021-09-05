#include<bits/stdc++.h>
using namespace std;

int getMaxGold(vector<vector<int>> mine, int row){

    int path1 = 0;
    int path2 = 0;
    int path3 = 0;
    for(int col = 1; col <=mine[row].size(); col++){
        if (col < mine[row].size()){
            path1 = getMaxGold(mine, row - 1);
            path2 = getMaxGold(mine, row);
            path3 = getMaxGold(mine, row + 1);
        }
    } 
    int maxv = mine[row][col]max(path1, max(path2, path3));

}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> mine(n, vector<int>(m, 0)); 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mine[i][j];
        }
    }

    int ans = getMaxGold(mine, 0, 1);
    return 0;
}