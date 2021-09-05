#include <iostream>
#include <climits>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--){
            int minv = INT_MAX;
        
            if (nums[i] == 0)
                dp[i] = 0;
            else {
                for(int j = 1; j <= nums[i] && (i + j) <= n; j++){
                    minv = min(minv, dp[i+j]);
                }
            }
           
            if (dp[i])
                dp[i] = 1 + minv;
        
        }
        return dp[0];        
    }
};
