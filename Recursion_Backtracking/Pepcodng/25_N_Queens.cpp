#include <iostream>
#include <vector>
using namespace std;


bool isPlaceSafeForQueen(vector<vector<int>> chess, int row, int col){
    for(int i = row - 1, j = col; i >= 0; i-- ){
        if (chess[i][j] == 1)
            return false;
    }
    
    for(int i = row - 1, j = col - 1; (i >= 0 && j >= 0); i--, j--){
        if (chess[i][j] == 1)
            return false;
    }
    for(int i = row - 1, j = col + 1; (i >= 0 && j < chess.size()); i--, j++){
        if (chess[i][j] == 1)
            return false;
    }
    
    return true;
}

void printQueens(vector<vector<int>> chess, string path, int row){
    
    if (row == chess.size()){
        cout << path <<".\n";
        return;
    }
      
    for(int col = 0; col < chess.size(); col++){
        chess[row][col] = 1;
        if (isPlaceSafeForQueen(chess, row, col)){
            printQueens(chess, path + to_string(row) + "-" + to_string(col) + "," , row + 1);
            chess[row][col] = 0; 
        }
    }
}
int main(){
    int n; cin >> n;
    vector<vector<int>> chess(n, vector<int> (n, 0)) ;
    printQueens(chess, "", 0);
}