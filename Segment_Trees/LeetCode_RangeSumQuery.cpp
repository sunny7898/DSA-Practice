#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
vector<int> sgmntTree;
int numsSize;
void buildTree(vector<int>& nums, int start, int end, int sgmntIdx){
    
    if (start == end){
        sgmntTree[sgmntIdx] = nums[start];
        return;
    }
    int mid = (start + end) / 2;
    
    int lSgmntIdx = 2 * sgmntIdx;
    buildTree(nums, start, mid, lSgmntIdx);
    
    int rSgmntIdx = 2 * sgmntIdx + 1;
    buildTree(nums, mid+1, end, rSgmntIdx);
    
    sgmntTree[sgmntIdx] = sgmntTree[lSgmntIdx] + sgmntTree[rSgmntIdx];
}

NumArray(vector<int>& nums) {
    numsSize = nums.size();
    if (numsSize){
        sgmntTree.resize(4*numsSize, 0);
        buildTree(nums, 0, numsSize-1, 1);
    }
}

void updateHelper(int start, int end, int sgmntIdx, int idx, int val){
    
    if (start == end){
        sgmntTree[sgmntIdx] = val;
        return;
    }
    
    int  mid = (start + end) / 2;
    if (idx <= mid)
        updateHelper(start, mid, 2*sgmntIdx, idx, val);
    else 
        updateHelper(mid + 1, end, 2*sgmntIdx+1, idx, val);
    
    sgmntTree[sgmntIdx] = sgmntTree[2*sgmntIdx] + sgmntTree[2*sgmntIdx+1];
    
}
void update(int index, int val) {
    if (index < 0 || index >= numsSize)
        return;
    updateHelper(0, numsSize-1, 1, index+1, val);
}

int sumRangeHelper(int start, int end, int left, int right, int sgmntIdx){
    if (start > right || end < left)
        return 0;
            
    if (start >= left && end <= right)
        return sgmntTree[sgmntIdx];
    
    int mid = (start + end) / 2;
    int lAns = sumRangeHelper(start, mid, left, right, 2*sgmntIdx);
    int rAns = sumRangeHelper(mid+1, end, left, right, 2*sgmntIdx+1);
    return lAns + rAns;
}
int sumRange(int left, int right) {
    return sumRangeHelper(0, numsSize-1, left, right, 1);
}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */