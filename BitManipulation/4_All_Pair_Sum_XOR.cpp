#include<bits/stdc++.h>
#define lli long long int 
using namespace std;

class Solution {
public:
    int xorSumPair(vector<int> arr){
        int len = arr.size();
        lli res = 0; 
        
        for(int i=0; i<len; i++)
            res ^= (arr[i]*2);
        
        return res;
    }
};

int main() {
    int n; cin >> n; 
    vector<int> arr;
    for(int i=0; i<n; i++){
        int ele; cin >> ele;
        arr.push_back(ele);
    }
    Solution obj; 
    cout << obj.xorSumPair(arr);
}