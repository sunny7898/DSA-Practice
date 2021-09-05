#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n; cin >> n; 
    int mask = 1;
    while(!(n & mask))
        mask = (mask << 1);
    string str = "";
    while (mask){
        str+= to_string(mask%2);
        mask = mask/2;
    };

    reverse(str.begin(), str.end());
    cout << str;
}