#include<iostream>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        int maxv = 0;
        for(int i=N; i>0; i--){
            if (maxv < (maxv ^ i)){
                maxv = maxv ^ i;
                cout << i << " ";
            }
        }
        cout << maxv<<endl;
    }
    return 0;
}