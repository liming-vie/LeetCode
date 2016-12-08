class Solution {
public:
    bool find(vector<int>&nums, int& target, int l, int r) {
        if (l>r)    return false;
        int mid;
        while(l<r && nums[l]==nums[r])  ++l;
        if (nums[l]<=nums[r]) {
            while(l<=r){
                mid=(l+r)>>1;
                if(nums[mid]==target)   return true;
                if(nums[mid]<target)    l=mid+1;
                else    r=mid-1;
            }
            return false;
        }
        mid=(l+r)>>1;
        return find(nums,target, l,mid) || find(nums,target,mid+1,r);
    }
    bool search(vector<int>& nums, int target) {
        return find(nums,target, 0, nums.size()-1);
    }
};