class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==1) {
            res.push_back(nums);
            return res;
        }
        
        for(int i=0; i<nums.size(); ++i) {
            vector<int> cur(nums);
            cur.erase(cur.begin()+i);
            auto t=permute(cur);
            for(int j=0; j<t.size(); ++j) {
                t[j].insert(t[j].begin(), nums[i]);
                res.push_back(t[j]);
            }
        }
        return res;
    }
};