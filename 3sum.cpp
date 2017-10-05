class Solution {
public:
#define ADDL() {++l; while(l<r && nums[l-1] == nums[l])  ++l;}
#define MINUSR() {--r; while(l<r && nums[r+1] == nums[r]) --r;}

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            if(i && nums[i] == nums[i-1])   continue;
            int l=i+1, r=n-1;
            int target=-nums[i];
            while(l<r) {
                int sum = nums[l]+nums[r];
                if(sum < target) 
                    ADDL()
                else if(sum > target)
                    MINUSR()
                else {
                    vector<int> cur{nums[i], nums[l], nums[r]};
                    res.push_back(cur);
                    ADDL()
                    MINUSR()
                }
            }
        }
        
        return res;
    }
};