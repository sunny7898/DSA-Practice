#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    // Step1: Taking xor of all
    int res = 0;
    for(int i=0; i<n; i++){
        res ^= arr[i];
    }

    // Step2: Finding the rightmost set bit in the res.
    int set_bit_no = (res ^ (~(res-1)));
        
    // Step3: Finding all those elements in the array which has set bit on the same index.
     
    vector<int> sep;
    for(int i=0; i<n; i++){
        if (arr[i] & set_bit_no)
            sep.push_back(arr[i]);
    }
    
    // Step 4: Take the xor of res stored in a temp with all these elements, it will give us one of the non-repeating element.
    int n1 = 0;
    for(int i=0; i<sep.size(); i++){
        n1 = res ^ sep[i];
    }

    // Step 5: Take the xor of this number again with res, it will give us second number.
    int n2 = n1 ^ res;
    cout << n1 << " " << n2;
    return 0;
}