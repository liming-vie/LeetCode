class Solution {
public:
    // three way partition
    void sortColors(vector<int>& nums) {
        if(nums.size()<2)   return;
        
        int i=0, l=0, r=nums.size()-1;
        while(i<=r) {
            if(nums[i]==1)    ++i;
            else if(nums[i]>1)  swap(nums[i], nums[r--]);
            else swap(nums[i++], nums[l++]);
        }
    }
};