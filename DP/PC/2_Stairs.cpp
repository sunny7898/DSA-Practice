#include <iostream>
using namespace std;

int cs(int n){
    
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    
    int path1 = cs(n-1);
    int path2 = cs(n-2);
    int path3 = cs(n-3);

    int tpath = path1 + path2 + path3;
    return tpath; 
}

int csMemoized(int n, int *qb){
    
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (qb[n] > 0)
        return qb[n];

    int path1 = csMemoized(n-1, qb);
    int path2 = csMemoized(n-2, qb);
    int path3 = csMemoized(n-3, qb);

    int tpath = path1 + path2 + path3;
    qb[n] = tpath;
    return tpath; 
}

int csTabulative(int n){
    int *dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;

    int qb[n+1] = {0};
    cout << csMemoized(n, qb) << "\n";

    cout<<csTabulative(n)<<endl;
}