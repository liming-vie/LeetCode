class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0, res=0;
        for (int i=1; i<=nums.size(); ++i) {
            if (i==nums.size() || nums[i] <= nums[i-1]) {
                res=max(res, i-start);
                start=i;
            }
        }
        return res;
    }
};