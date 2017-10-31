class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(); if (!n) return 0;
        int maxp=nums[0], minp=nums[0];
        int res=nums[0];
        for (int i=1; i<n; ++i) {
            int t1=minp*nums[i];
            int t2=maxp*nums[i];
            minp = min(min(t1, t2), nums[i]);
            maxp = max(max(t1, t2), nums[i]);
            res = max(res, maxp);
        }
        return res;
    } 
};