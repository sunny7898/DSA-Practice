#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    if (s.length() == 0)
        return vector<string> (1, "");

    vector<string> sres = gss(s.substr(1));
    
    vector<string> res;
    for(string str: sres)
        res.push_back("" + str);
    for(string str: sres)
        res.push_back(s[0] + str);
    return res;
}

int main(){
    string s; cin >> s;
    vector<string> ans = gss(s);
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
}