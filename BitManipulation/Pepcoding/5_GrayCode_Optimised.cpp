#include<bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n){
    vector<int> res(1, 0);

    for(int i=0; i<n; i++){
        int size = res.size();
        for(int j=size-1; j>=0; j--){
            res.push_back(res[j] | (1 << i));
        }
    }
    return res;
}

int main() {
    int n; cin >> n; 
    vector<int> res = grayCode(n);
    for(int it: res){
        cout << it << " ";
    }
    return 0;
}