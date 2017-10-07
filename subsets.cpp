class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        int size = 1 << nums.size();
        for (int i=0; i<size; ++i) {
            cur.clear();
            for (int j=0; j<nums.size(); ++j) {
                if (i&(1<<j)) {
                    cur.push_back(nums[j]);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};