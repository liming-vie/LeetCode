class Solution {
public:
#define PROCL \
while(l<r && nums[l]==nums[l+1])    \
++l;

#define PROCR \
while(l<r && nums[r]==nums[r-1])    \
--r;

    bool func(vector<int>& nums, int l, int r, int target) {
        if(l>r) return false;
        
        PROCL
        PROCR
        
        int mid=(l+r)>>1;
        if(nums[mid]==target)   return true;
        
        if(nums[l]<nums[r]) {
            while(l<=r) {
                mid=(l+r)>>1;
                if(nums[mid]<target)  {
                    l=mid+1;
                    PROCL
                }
                else if(nums[mid]>target) {
                    r=mid-1;
                    PROCR
                }
                else    return true;
            }
            return false;
        }
        
        return func(nums, l, mid-1, target) || func(nums,mid+1, r, target);
    }

    bool search(vector<int>& nums, int target) {        
        return func(nums, 0, nums.size()-1, target);
    }
};