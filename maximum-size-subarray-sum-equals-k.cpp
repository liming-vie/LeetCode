#define MAX(a,b) (a)>(b)?(a):(b)

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) res = i+1;
            else if (mp.find(sum-k) != mp.end()) {
                res = MAX(res, i-mp[sum-k]);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return res;
    }
};