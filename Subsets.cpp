class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;
    
    void func(vector<int>& nums, int vi) {
        if(vi==nums.size()) {
            res.push_back(cur);
            return;
        }
        
        cur.push_back(nums[vi]);
        func(nums, vi+1);
        cur.pop_back();
        
        func(nums, vi+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        func(nums, 0);
        return res;
    }
};