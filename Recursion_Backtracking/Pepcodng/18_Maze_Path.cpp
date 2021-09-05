#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {

    if (sr == dr && sc == dc)
        return vector<string> (1, "");

    vector<string> pathh;
    vector<string> pathv;
    
    if (sc < dc)
        pathh = getMazePaths(sr, sc+1, dr,dc);
    
    if (sr < dr)
        pathv = getMazePaths(sr+1, sc, dr,dc);
    
    vector<string> resPaths;
    for(string path: pathh){
        resPaths.push_back("h" + path);
    }
    for(string path: pathv){
        resPaths.push_back("v" + path);
    }   

    return resPaths;

}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}