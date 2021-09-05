#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id){

    if (n==0)
        return; 

    toh (n-1, t1id, t3id, t2id); // will print instructions to move n-1 disks from t1 to t3 using t2 following rules.

    cout << n << "["<< t1id << " -> " << t2id <<"]\n";

    toh(n-1, t3id, t2id, t1id);  // will print instructions to move n-1 disks from t3 to t2 using t1 following rules.

}

int  main() {
    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
}