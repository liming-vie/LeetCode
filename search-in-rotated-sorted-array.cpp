class Solution {
public:
    #define MID(left, right) (left+((right-left)>>1))
    int func(vector<int>&nums, int left, int right, int target) {
        if(left>right)  return -1;
        // binary search
        if(nums[left] <= nums[right]) {
            while(left<=right) {
                int mid=MID(left, right);
                if(nums[mid]==target)   return mid;
                else if(nums[mid]>target)   right=mid-1;
                else    left=mid+1;
            }
            return -1;
        }
        else {
            int mid=MID(left, right);
            int a=func(nums, left, mid, target);
            if(a!=-1)   return a;
            return func(nums, mid+1, right, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return func(nums, 0, nums.size()-1, target);
    }
};