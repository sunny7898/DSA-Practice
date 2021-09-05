#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,K; cin >> N >> K;
    int prefix[N+1];
    prefix[0] = 0;
    for(int i=1; i<=N; i++){
        prefix[i] = prefix[i-1] ^ i;
    }
    for(int i=0; i<N; i++)
        cout<<prefix[i] <<" ";

    

}