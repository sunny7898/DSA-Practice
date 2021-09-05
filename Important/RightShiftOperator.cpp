#include<bits/stdc++.h>
using namespace std;
void printBinary(const unsigned char val) {
  for(int i = 7; i >= 0; i--)
    if(val & (1 << i))
      cout << "1";
    else
      cout << "0";
    cout << "\n";
} 


int main() {
    int t; cin >> t;
    while(t--){
        int num; cin >> num;
        char a = num;
        cout << num <<" ";
        printBinary(a);
        cout << (num>>3) << " ";
        printBinary(a>>3);    
    }

    return 0;
}