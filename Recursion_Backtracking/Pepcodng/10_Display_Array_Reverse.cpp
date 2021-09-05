#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    if (idx == n)
        return ;

    // last se index 1 tk krde 
    display(arr, idx+1, n);

    // baki  0th main kr dunga
    cout << arr[idx] << "\n";
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}