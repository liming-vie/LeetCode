class Solution {
public:
    int func(const vector<int>& nums, int target, int left, int right) {
        if (left > right)   return -1;
        
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target)    return mid;
        
        if (nums[right] < nums[left]) {
            int tmp = func(nums, target, left, mid-1);
            if (tmp >= 0)   return tmp;
            return func(nums, target, mid+1, right);
        } else {
            while (left <= right) {
                mid = left + ((right-left)>>1);
                if (nums[mid] == target)    return mid;
                else if (nums[mid] < target)    ++left;
                else    --right;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return func(nums, target, 0, nums.size()-1);
    }
};