class Solution {
public:
    inline int L(const vector<int>& nums, int l, int r) {
        ++l;
        while (l<r && nums[l]==nums[l-1])   ++l;
        return l;
    }
    
    inline int R(const vector<int>& nums, int l, int r) {
        --r;
        while (l<r && nums[r]==nums[r+1])   --r;
        return r;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n=nums.size(), diff = ~(1<<31), res;
        
        for (int i=0; i<n; ++i) {
            if (i && nums[i] == nums[i-1])  continue;
            int t=target-nums[i];
            int l=i+1, r=n-1;
            while (l<r) {
                int sum = nums[l]+nums[r];
                if (sum < t)    l=L(nums, l, r);
                else if (sum > t) r=R(nums, l, r);
                else return target;
                int tmp=abs(t-sum);
                if (tmp < diff) {
                    diff = tmp;
                    res = sum+nums[i];
                }
            }
        }
        
        return res;
    }
};