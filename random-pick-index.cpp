class Solution {
public:
    Solution(vector<int> nums) : nums(nums) {
        srand(time(NULL));
    }
    
    int pick(int target) {
        int res;
        int n=0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == target) {
                if((rand() % (++n)) == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */