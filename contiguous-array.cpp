class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum=0, res=0;
        for (int i=0; i<nums.size(); ++i) {
            sum+=nums[i] ? 1 : -1;
            if (mp.find(sum)!=mp.end()) {
                res = max(res, i-mp[sum]);
            }
            else    mp[sum]=i;
            if (sum==0) res=i+1;
        }
        return res;
    }
};