#include<bits/stdc++.h>
using namespace std;

vector<string> getKPC(string inp){
    static vector<string> key_map({".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"});

    if (inp.length() == 0)
        return vector<string> (1, "");
    
    vector<string> sres = getKPC(inp.substr(1));

    int idx = inp[0] - '0';

    vector<string> res;    
    for(char ch: key_map[idx] ) {
        for(string st: sres)
            res.push_back(ch + st);
    }

    return res;  
}
int main() {
    string inp; cin >> inp;
    vector<string> ans = getKPC(inp);
    int cnt = 0;
    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}