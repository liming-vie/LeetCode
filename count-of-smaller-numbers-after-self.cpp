class Solution {
public:
    vector<int> tmp;
    vector<int> tmpi;
    vector<int> count;
    vector<int> idxs;
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)  return;
        
        int mid=left+((right-left)>>1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        
        int l=left, r=mid+1;
        int idx=left;
        while (l<=mid || r<=right) {
            if (r>right || (l<=mid && nums[l]<=nums[r])) {
                count[idxs[l]] += r-mid-1;
                tmpi[idx]=idxs[l];
                tmp[idx++]=nums[l++];
            } else {
                tmpi[idx]=idxs[r];
                tmp[idx++]=nums[r++];
            }
        }
        for (int i=left; i<=right; ++i) {
            nums[i]=tmp[i];
            idxs[i]=tmpi[i];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        tmp=nums;
        tmpi=nums;
        count=vector<int>(nums.size(), 0);
        idxs=vector<int>(nums.size());
        for (int i=0; i<nums.size(); ++i)    idxs[i]=i;
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }
};