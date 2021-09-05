#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int INT_SIZE = 8 * sizeof(unsigned int);
    int count[INT_SIZE] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (arr[j] & (1 << i))
                count[i]++;
        }
    }

    unsigned res = 0;
    for(int i=0; i<INT_SIZE; i++)
        res+= (count[i]%k) * (1 << i);
    
    cout << res;
    return 0;
}