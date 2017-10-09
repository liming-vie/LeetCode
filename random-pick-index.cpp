class Solution {
public:
    Solution(vector<int> nums) : nums(nums) {
    }
    
    int pick(int target) {
        int res, count = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != target) continue;
            if (rand() % (++count) == 0) res = i;
        }
        return res;
    }
    
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */