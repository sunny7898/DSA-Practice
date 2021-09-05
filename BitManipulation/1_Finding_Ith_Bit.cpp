#include<bits/stdc++.h>
using namespace std;

int main() {
    uint32_t num1; cin >> num1;

    // By index
    int i; cin >> i;
    cout << (num1 & (1 << i));

    cout << "\n";
    // By position
    int p; cin >> p;
    cout << (num1 & (1 << (p-1)));
    return 0;
}