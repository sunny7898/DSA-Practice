#include<bits/stdc++.h>
using namespace std;

vector<int> printSubstrings(string str, int n){
    vector<string> res;

    for(int i=0; i<str.length(); i++){
        res.push_back(to_string(str[i]));
        for(int j=i+1; j<str.length(); j++){
            res.push_back((res[j-1]+str[j]))
        }
    }
}

int main() {
    string str; cin >> str;
    printSubstrings(str, str.length());
    
    return 0;
}