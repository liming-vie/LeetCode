class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)    return 0;
        
        int l=0,r=n-1,mid;
        while(l<r) {
            mid=l+((r-l)>>1);
            if(nums[mid]==target)   return mid;
            if(nums[mid]<target)    l=mid+1;
            else    r=mid-1;
        }
        if(nums[l]>=target) return l;
        return l+1;
    }
};