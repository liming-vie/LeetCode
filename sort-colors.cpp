class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int i=0;
        while (i<=r) {
            if (nums[i] == 1)   ++i;
            else if (nums[i] == 2) swap(nums[i], nums[r--]);
            else swap(nums[i++], nums[l++]);                                                      
        }
    }
};
