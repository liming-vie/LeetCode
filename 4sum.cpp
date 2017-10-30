class Solution {
public:
    inline int L(const vector<int>& nums, int l, int r) {
        ++l;
        while (l<r && nums[l]==nums[l-1])   ++l;
        return l;
    }
    
    inline int R(const vector<int>& nums, int l, int r) {
        --r;
        while (l<r && nums[r]==nums[r+1])   --r;
        return r;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; ++i) {
            if (i && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<n; ++j) {
                if (j!=i+1 && nums[j]==nums[j-1]) continue;
                int l=j+1, r=n-1;
                int t=target-nums[i]-nums[j];
                while (l<r) {
                    int sum=nums[l]+nums[r];
                    if (sum < t)    l=L(nums, l, r);
                    else if (sum>t) r=R(nums, l, r);
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l=L(nums, l, r);
                        r=R(nums, l, r);
                    }
                }
            }
        }
        return res;
    }
};