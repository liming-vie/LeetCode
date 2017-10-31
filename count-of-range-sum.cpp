class Solution {
public:
    vector<long long> tmp;
    
    int mergeSort(vector<long long>& nums, int lower, int upper, int left, int right) {
        if (left>=right)    return 0;
        int mid=left+((right-left)>>1);
        int res = mergeSort(nums, lower, upper, left, mid) +
                mergeSort(nums, lower, upper, mid+1, right);
        
        int low=mid+1, up=mid+1;
        int idx=left, l=left, r=mid+1;
        for (; l<=mid; ++l) {
            while (low <= right && nums[low]-nums[l]<lower)   ++low;
            while (up <= right && nums[up]-nums[l]<=upper)   ++up;
            while (r<=right && nums[r]<nums[l]) tmp[idx++]=nums[r++];
            tmp[idx++]=nums[l]; 
            res += up-low;
        }
        for (int i=left; i<idx; ++i) {
            nums[i]=tmp[i];
        }
        return res;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sums(nums.size()+1);
        sums[0]=0;
        for (int i=0; i<nums.size(); ++i)
            sums[i+1] = sums[i]+nums[i];
        tmp=sums;
        return mergeSort(sums, lower, upper, 0, sums.size()-1);
    }
};