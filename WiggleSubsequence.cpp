class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(!n)  return 0;
        vector<int> d(n, 1);
        vector<int> p(n, 1);
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(nums[i]>nums[j]) {
                    d[i] = max(d[i], p[j]+1);
                }
                else if(nums[i]<nums[j]) {
                    p[i] = max(p[i], d[j]+1);
                }
            }
        }
        return max(p[n-1], d[n-1]);
    }
};