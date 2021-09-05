#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

vector<int> res;


void printSubsets(vector<ll> inp, vector<ll> out, ll K){
    if(inp.size() == 0){
        if(out.size() == K) {
            ll xorv = 0;
            ll i =0;
            if(res.size() != 0){
                vector<int> temp;
                for(i=0; i<out.size(); i++){             
                    temp.push_back(out[i]);
                    xorv = xorv ^ out[i];
                }
                if(xorv > res[K]){
                    res.clear();
                    res = temp;
                    res.push_back(xorv);
                }
            }
            else{
                for(i=0; i<out.size(); i++){             
                    res.push_back(out[i]);
                    xorv = xorv ^ out[i];
                }
                res.push_back(xorv);
            }
            for(int i=0; i<res.size(); i++){
                cout << res[i] << " ";
            }
            cout<<"\n";
        }
        return;
    }



    vector<ll> op1(out.begin(), out.end());
    vector<ll> op2(out.begin(), out.end());

    op2.push_back(inp[0]);
    inp.erase(inp.begin() + 0);

    printSubsets(inp, op1, K);
    printSubsets(inp, op2, K);
    
}

int main(){
    ll T; cin >> T;
    while(T--) {
        ll N;
        ll K; cin >> N >> K;

        if (K==1){
            cout << N <<'\n';
            continue;
        }

        vector<ll> inp;
        for(ll i=0; i<N; i++)
            inp.push_back(i+1);

        vector <ll> out;
        printSubsets(inp, out, K);

        for(int i=0; i<K; i++)
            cout << res[i] <<" ";
        cout<<'\n';
    }
    return 0;
}


