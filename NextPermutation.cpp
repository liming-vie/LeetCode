class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        // from right to left, find the first one violate increase trend
        while(i>=0 && nums[i]>=nums[i+1])   --i;
        
        // biggest
        if(i<0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // from right to left, find the first one bigger than nums[i]
        int j=nums.size()-1;
        while(j>i && nums[j]<=nums[i])  --j;
        //swap the two number
        swap(nums[i], nums[j]);
        // reverse the right part of nums[i]
        reverse(nums.begin()+i+1, nums.end());
    }
};