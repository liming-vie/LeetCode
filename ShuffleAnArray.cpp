class Solution {
public:
    Solution(vector<int> nums) : nums(nums), ori(nums) {
        n = nums.size();
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums = ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=0; i<n; ++i) {
            swap(nums[i], nums[rand()%n]);
        }
        return nums;
    }
private:
    int n;
    vector<int> nums;
    vector<int> ori;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */