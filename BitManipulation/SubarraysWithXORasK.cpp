#include<bits/stdc++.h>
using namespace std;

int subarrayWithXORasK(vector<int> &A, int B){
    map<int, int> freq; 
    int cnt = 0;
    int xorr = 0;
    for(auto it: A){
        cout << it << " ";
        xorr = xorr ^ it;

        if (xorr == B){
            cnt++;
        }

        if(freq.find(xorr ^ B) != freq.end())
            cnt += freq[xorr ^ B];
        
        freq[xorr] += 1;
    }   
    return cnt;
}

int main(){
    vector<int> arr; 
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);

    int cnt = subarrayWithXORasK(arr, 15);
    cout << endl<<  cnt;

    return 0;    
}