class Solution {
public:
    vector<vector<int>> res;
    
    void func(vector<int>& nums, int vi, vector<int>& cur, int sum, int target) {
        if(vi == nums.size()) {
            if(sum==target)
                res.push_back(cur);
            return;
        }
        // not put this number
        func(nums, vi+1, cur, sum, target);
        int s;
        for(s=sum+nums[vi]; s<=target; s+=nums[vi]) {
            cur.push_back(nums[vi]);
            func(nums, vi+1, cur, s, target);
        }
        s-=nums[vi];
        while(s>sum) {
            s-=nums[vi];
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        func(candidates, 0, cur, 0, target);
        return res;
    }
};