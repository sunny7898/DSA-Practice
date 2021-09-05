#include<iostream>
#include<vector>
using namespace std;

void floodfill(vector<vector<int>>  maze, int row, int col, string psf, vector<vector<bool>> visited) {
    
    // It is important to write maze[row][col] = 1 in the end, because if row and col would have been not a part  of matrix, then we would have been trying to compare its value, which would have given us array index out of bound. 
    
    if (row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || maze[row][col] == 1 || visited[row][col] == true) 
        return;  

    if ((row == maze.size()-1) && (col == maze[0].size()-1)){
        cout << psf <<"\n";
        return; 
    }
    visited[row][col] = true;
    floodfill(maze, row - 1, col, psf + "t", visited);
    floodfill(maze, row, col - 1, psf + "l", visited);
    floodfill(maze, row + 1, col, psf + "d", visited);
    floodfill(maze, row, col + 1, psf + "r", visited);  
    visited[row][col] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    vector<vector<bool>> visited(n, vector < bool > (m));
    floodfill(maze, 0, 0, "", visited);
}