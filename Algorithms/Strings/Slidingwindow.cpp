#include<iostream>
#include<vector>
using namespace std;

vector<int> slidingWindow(string main, string pat){
    vector<int> res;
    for(int i=0; i<main.length()-pat.length()+1; i++){
        int cnt = 0;
        for(int j = 0; j< pat.length(); j++){
            if (pat[j] == main[i+j]){
                cnt++;
            }
        }
        if (cnt == pat.length())
            res.push_back(i);
    }
    return res;
}

int main(){
    int T;
    cin >> T;

    cin.ignore(); 
    while (T--){
        string main = ""; 
        string pattern = "";
        getline(cin, main);
        getline(cin, pattern);
        vector<int> idx = slidingWindow(main, pattern);
        for(int it: idx){
            cout << it << " ";
        }
    }
    return 0;

}