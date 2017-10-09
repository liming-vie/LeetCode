class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void dps(const vector<int>& nums, int vi, bool prev) {
        if (vi == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        if (!(vi && nums[vi]==nums[vi-1] && prev))
            dps(nums, vi+1, false);
        
        cur.push_back(nums[vi]);
        dps(nums, vi+1, true);
        cur.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dps(nums, 0, false);
        return res;
    }
};