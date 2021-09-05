#include<bits/stdc++.h>
using namespace std;

void printTargetSumSubsets(vector<int> arr, int idx, string set, int tar, int sum) {
    
    if (sum > tar)
        return ;
    if (idx == arr.size()){
        if (sum == tar){
            cout << set << "." <<"\n";
        }
        return ;
    }
    string temp = set + to_string(arr[idx]);
    printTargetSumSubsets(arr, idx + 1, temp + ", ", tar, sum + arr[idx]);
    printTargetSumSubsets(arr, idx + 1, set, tar, sum);
}

int main(){

    // set is the subset
    // sos is sum of subset
    // tar is target
    int n; cin >> n;
    vector<int> arr; 
    for(int i=0; i<n; i++){
        int ele ; cin >> ele;
        arr.push_back(ele);
    }
    int m; cin >> m;
    printTargetSumSubsets(arr,0, "", m, 0) ;
}