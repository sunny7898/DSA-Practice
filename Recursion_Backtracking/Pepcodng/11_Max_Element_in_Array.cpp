#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){

    if (idx == n-1)
        return arr[idx];

    int max1ton = max(arr, idx+1, n) ;
    return (arr[idx] > max1ton ? arr[idx]: max1ton);
}

int main(){
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
