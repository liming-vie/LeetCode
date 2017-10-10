class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, res=0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int n : nums) {
            sum += n;
            int tmp = sum - k;
            if (mp.find(tmp) != mp.end()) {
                res += mp[tmp];
            }
            mp[sum] += 1;
        }
        return res;
    }
};