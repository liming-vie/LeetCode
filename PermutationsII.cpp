class Solution {
public:
    vector<vector<int>> res;
    
    void func(vector<int>&nums, int vi) {
        if(vi==nums.size()) {
            res.push_back(nums);
            return;
        }
            
        for(int i=vi; i<nums.size(); ++i) {
            // nums[vi,i) != nums[i]
            bool flag=true;
            for(int j=vi; j<i; ++j) {
                if(nums[j] == nums[i]) {
                    flag=false;
                    break;
                }
            }
            if(!flag)   continue;
            swap(nums[i], nums[vi]);
            func(nums, vi+1);
            swap(nums[i], nums[vi]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        func(nums, 0);
        return res;
    }
};