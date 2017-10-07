class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void dfs(const vector<int>& nums, int vi) {
        if (vi == nums.size()) {
            res.push_back(cur);
            return ;
        }
        
        dfs(nums, vi+1);
        
        cur.push_back(nums[vi]);
        dfs(nums, vi+1);
        cur.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};