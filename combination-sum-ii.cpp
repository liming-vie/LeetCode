class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void func(const vector<int>& nums, int vi, int target, bool last) {
        if (target < 0) {
            return;
        }
        if (vi==nums.size()) {
            if (target == 0) {
                res.push_back(cur);
            } 
            return;
        }
        
        if (!(vi && nums[vi]==nums[vi-1] && last)) {
            func(nums, vi+1, target, false);
        }
        
        cur.push_back(nums[vi]);
        func(nums, vi+1, target-nums[vi], true);
        cur.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        func(candidates, 0, target, false);
        
        return res;
    }
};