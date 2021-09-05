#include<bits/stdc++.h>
using namespace std;

class Solution {
    void binary2decimal(vector<string> res){
        vector<int> dec;
        for(string str: res){
            long long int num = 0; 
            int k = 0;
            for(char ch: str){
                num += (ch - '0') * (1 << k);
                k++;
            }
            cout << num <<" ";
        }
    }
    public: 
    vector<string> getGrayCode(int n){
        if (n==1){
            vector<string> svec;
            svec.push_back("0");
            svec.push_back("1");
            return svec;            
        }

        vector<string> smallOp = getGrayCode(n-1);
        int sOPSize = smallOp.size();
        
        vector<string> res;      
        for(int i=0; i<sOPSize; i++){
            string str = "0" + smallOp[i];
            res.push_back(str);
        }
        for(int i=sOPSize-1; i>=0; i--){
            string str = "1" + smallOp[i];
            res.push_back(str);
        }
        return res;
    }

    void printGrayCode(int n){
        vector<string> res;
        res = getGrayCode(n);
        
        binary2decimal(res);
    }

};

int main() {
    int n; cin >> n;
    vector<int> res; 
    Solution obj;
    obj.printGrayCode(n);
    return 0;
}