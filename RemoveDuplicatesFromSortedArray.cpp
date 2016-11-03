class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        
        int idx=1, vi=0;
        while((++vi)<n) {
            if(nums[vi]==nums[vi-1])    continue;
            nums[idx++]=nums[vi];
        }
        return idx;
    }
};