class Solution {
public:
    bool valid(const vector<int>&nums, int target, int m) {
        int count=1, sum=0;
        for (int n:nums) {
            sum+=n;
            if (sum>target) {
                if (++count>m)  return false;
                sum=n;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int size=nums.size();
        long long l=nums[0], r=nums[0];
        for (int i=1; i<size; ++i) {
            l=(l>nums[i]?l:nums[i]);
            r+=nums[i];
        }
        
        long long mid;
        while (l<=r) {
            mid = l+((r-l)>>1);
            if (valid(nums, mid, m))
                r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};