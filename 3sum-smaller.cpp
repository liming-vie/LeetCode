class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int res=0;
        for (int i=0; i<(int)nums.size()-2; ++i) {
            int l=i+1, r=nums.size()-1;
            int sum=nums[i]+nums[l]+nums[r];
            while (l<r) {
                if (sum<target) {
                    res += r-l;
                    sum = sum-nums[l]+nums[++l];
                } else {
                    sum = sum-nums[r]+nums[--r];
                }
            }
        }
        return res;
    }
};