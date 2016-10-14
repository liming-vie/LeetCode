class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,max=(1<<31);
        for(int i=0; i<nums.size(); ++i) {
            sum = nums[i] + (sum < 0 ? 0 : sum);
            max = max > sum ? max : sum;
        }
        return max;
    }
};