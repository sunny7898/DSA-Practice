#include<iostream>
#include<vector>
using namespace std;

void printSubsets(vector<int> inp, vector<int> out, int K){
    if(inp.size() == 0){
        if(out.size() == K) {
            for(auto it: out)
                cout << it <<" ";
            cout<<'\n';   }
        return;
    }

    vector<int> op1(out.begin(), out.end());
    vector<int> op2(out.begin(), out.end());

    op2.push_back(inp[0]);
    inp.erase(inp.begin() + 0);

    printSubsets(inp, op1, K);
    printSubsets(inp, op2, K);
    
}

int main(){
    int N, K; cin >> N >> K;
    vector<int> inp;
    for(int i=0; i<N; i++)
        inp.push_back(i+1);

    vector <int> out;
    printSubsets(inp, out, K);
}