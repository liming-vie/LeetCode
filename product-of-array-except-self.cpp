class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, vi;
        long long tot=1;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i])  tot *= nums[i];
            else {
                ++zero;
                vi = i;
            }
        }
        if (zero == 0) {
            for (int i=0; i<nums.size(); ++i) {
                nums[i] = tot/nums[i];
            }
            return nums;
        } else {
            int n=nums.size();
            nums.resize(0);
            nums.resize(n, 0);
            if (zero == 1)  nums[vi] = tot;
        }
        return nums;
    }
};