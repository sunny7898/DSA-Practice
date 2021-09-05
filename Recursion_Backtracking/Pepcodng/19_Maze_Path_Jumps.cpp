#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if( (sr == dr) && (sc == dc ))
        return vector<string> (1, "");
    
    vector<string> resPath; 

    // For horizontal path: 
    for(int x = 1; x <= dc-sc; x++){
        vector<string> h_paths = getMazePaths(sr,  x+sc , dr, dc);
        for(string str: h_paths)
            resPath.push_back("h" + to_string(x) + str);
    }

    // For vertical path: 
    for(int y = 1; y <= dr-sr; y++){
        vector<string> v_paths = getMazePaths(y+sr, sc , dr, dc);
        for(string str: v_paths)
            resPath.push_back("v" + to_string(y) + str);
    }
    
    // For diagonal path: 
    for(int d = 1; (d <= dr-sr) && (d <= dc-sc); d++){
        vector<string> d_paths = getMazePaths(sc+d, sr+d, dr, dc);
        for(string str: d_paths)
            resPath.push_back("d" + to_string(d) + str);
    }

    return resPath;
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
    vector<string> ans = getMazePaths(0, 0, n-1,m-1);
    display(ans);

    return 0;
}