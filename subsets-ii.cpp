class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    void func(vector<int>&nums, int vi, bool lastuse) {
        if(vi==nums.size()) {
            res.push_back(cur);
            return ;
        }
        func(nums, vi+1, false);
        
        if(vi && nums[vi]==nums[vi-1] && !lastuse)
            return;
            
        cur.push_back(nums[vi]);
        func(nums, vi+1, true);
        cur.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        func(nums, 0, false);
        return res;
    }
};