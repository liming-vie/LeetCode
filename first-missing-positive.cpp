class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; ++i)
            if (nums[i]<=0) nums[i]=n+1;
        for (int i=0; i<n; ++i)
            if (abs(nums[i]) <= n) {
                int idx = abs(nums[i])-1;
                nums[idx] = -abs(nums[idx]);
            }
        for (int i=0; i<n; ++i)
            if (nums[i] > 0)
                return i+1;
        return n+1;
    }
};