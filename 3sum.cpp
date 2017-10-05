class Solution {
public:
    int addLeft(const vector<int> &nums, int left, int right) {
        ++left;
        while (left < right && nums[left] == nums[left-1]) {
            ++left;
        }
        return left;
    }
    
    int minusRight(const vector<int> &nums, int left, int right) {
        --right;
        while (left < right && nums[right] == nums[right+1]) {
            --right;
        }
        return right;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; ++i) {
            if (i && nums[i] == nums[i-1])  {
                continue;
            }
            
            int l=i+1, r=n-1;
            while (l<r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l=addLeft(nums, l, r);
                    r=minusRight(nums, l, r);
                } else if (sum < 0) {
                    l=addLeft(nums, l, r);
                } else {
                    r=minusRight(nums, l, r);
                }
            }
        }
        
        return res;
    }
};