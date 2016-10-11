class Solution {
public:
    void mysort(vector<int>& nums, int left, int right, int target) {
        int l=left, r=right;
        int mid = l+((r-l)>>1);
        int tmp = nums[mid];
        nums[mid] = nums[right];
        while(l<r) {
            while(l<r && nums[l]<=tmp)  ++l;
            if(l<r) nums[r--] = nums[l];
            while(l<r && nums[r]>tmp)  --r;
            if(l<r) nums[l++] = nums[r];
        }
        nums[l] = tmp;
        if(l==target) {
            vector<int> tmp(nums);
            l=target;
            r=nums.size()-1;
            int idx=0;
            bool odd=false;
            while(l>=0 || r>target) {
                if(!odd && l>=0) {
                    nums[idx++] = tmp[l--];
                }
                else if(odd && r>target) {
                    nums[idx++] = tmp[r--];
                }
                odd = !odd;
            }
        }
        else if(l < target) 
            mysort(nums, l+1, right, target);
        else    mysort(nums, left, l-1, target);
    }
    void wiggleSort(vector<int>& nums) {
        mysort(nums, 0, nums.size() - 1, (nums.size() - 1) >> 1);
    }
};