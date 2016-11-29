class Solution {
public:
    vector<vector<int>> res;

    void func(vector<int>& nums, int vi) {
        if(vi==nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=vi; i<nums.size();++i) {
            swap(nums[vi], nums[i]);
            func(nums, vi+1);
            swap(nums[vi], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        func(nums, 0);
        return res;
    }
};