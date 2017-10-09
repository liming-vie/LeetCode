class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0, j=0;
        long long cursum = 0;
        int res = nums.size()+1;
        for (int j=0; j<nums.size(); ++j) {
            cursum += nums[j];
            if (cursum >= s) {
                while (i<=j && cursum - nums[i] >= s) {
                    cursum -= nums[i];
                    ++i;
                }
                int tmp = j-i+1;
                res = res < tmp ? res : tmp;
            }
        }
        if (res > nums.size())  return 0;
        return res;
    }
};