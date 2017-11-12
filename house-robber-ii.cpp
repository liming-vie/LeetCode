class Solution {
public:
    int helper(const vector<int>& nums, int start, int end, int rb) {
        int norob = 0;
        for (int i=start; i<=end; ++i) {
            int tmp = max(norob, rb);
            rb = max(norob+nums[i], rb);
            norob = tmp;
        }
        return max(norob, rb);
    }
    
    int rob(vector<int>& nums) {
        if (nums.size()<1)  return 0;
        
        return max(helper(nums, 1, nums.size()-2, nums[0]), helper(nums, 1, nums.size()-1, 0));
    }
};