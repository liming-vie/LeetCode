class Solution {
public:
    vector<int> tmp;
    
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)  return 0;
        
        int mid=left+((right-left)>>1);
        int count=mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right);
        
        int l=left, r=mid+1;
        int idx=left;
        int t=mid+1;
        for (; l<=mid; ++l) {
            while (t<=right && nums[l]>((long long)nums[t]<<1))   ++t;
            count += t-mid-1;
            while (r<=right && nums[r]<nums[l]) tmp[idx++]=nums[r++];
            tmp[idx++]=nums[l];
        }
        for (int i=left; i<idx; ++i)    nums[i]=tmp[i];
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        tmp=nums;
        return mergeSort(nums, 0, nums.size()-1);
    }
};