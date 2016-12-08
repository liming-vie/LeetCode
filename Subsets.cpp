class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        int size=1<<nums.size();
        for(int k=0; k<size; ++k) {
            cur.clear();
            for(int i=0; i<nums.size(); ++i) 
                if((1<<i) & k)
                    cur.push_back(nums[i]);
            res.push_back(cur);
        }
        return res;
    }
};