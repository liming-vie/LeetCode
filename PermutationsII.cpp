class Solution {
public:
    // use next permutation
    bool next(vector<int>& nums) {
        int i=nums.size()-1;
        while(i && nums[i]<=nums[i-1])   --i;
        if(i==0)    return false;
        
        --i;
        int j=nums.size()-1;
        while(j>i && nums[j]<=nums[i])  --j;
        
        swap(nums[i], nums[j]);
        
        reverse(nums.begin()+i+1, nums.end());
        return true;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while(next(nums)) {
            res.push_back(nums);
        }
        return res;
    }
};