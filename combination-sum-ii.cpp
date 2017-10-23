class Solution {
public:
    vector<vector<int>> res;
    vector<bool> use;
    
    void func(vector<int>& nums, int vi, vector<int>& cur, int sum, int target) {
        if(sum > target)    return;
        if(vi == nums.size()) {
            if(sum==target)
                res.push_back(cur);
            return;
        }
        // not put this number
        func(nums, vi+1, cur, sum, target);
        // only when thr previous one being used, the same one can be use
        if(vi && nums[vi] == nums[vi-1] && !use[vi-1])  return;
        // put once
        use[vi]=true;
        cur.push_back(nums[vi]);
        func(nums, vi+1, cur, sum+nums[vi], target);
        cur.pop_back();
        use[vi]=false;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        use.resize(candidates.size(), false);
        vector<int> cur;
        func(candidates, 0, cur, 0, target);
        return res;
    }
};
