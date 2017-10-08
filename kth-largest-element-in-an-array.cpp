class Solution {
public:
    int find(vector<int>& nums, int k, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int pivot = left+((right-left)>>1), val = nums[pivot];
        nums[pivot] = nums[right];
        
        int l=left, r=right;
        while(l<r) {
            while (l<r && nums[l] > val) ++l;
            if (l<r) nums[r--] = nums[l];
            while (l<r && nums[r] < val) --r;
            if (l<r) nums[l++] = nums[r];
        }
        
        if (l==k) return val;
        nums[l] = val;
        
        if (k < l) return find(nums, k, left, l-1);
        return find(nums, k, l+1, right);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, k-1, 0, nums.size()-1);
    }
};