class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> use;

    void func(vector<int>&nums, int vi) {
        if(vi==nums.size()) {
            res.push_back(cur);
            return ;
        }
        func(nums, vi+1);
        if(vi==0 || nums[vi]!=nums[vi-1] || use[vi-1]) {
            cur.push_back(nums[vi]);
            use[vi]=true;
            func(nums, vi+1);
            cur.pop_back();
            use[vi]=false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        use.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        func(nums, 0);
        return res;
    }
};