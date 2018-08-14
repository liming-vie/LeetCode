class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int n:nums1)   ++mp[n];
        
        vector<int> res;
        for (int n:nums2) {
            if (mp.find(n)!=mp.end()) {
                res.push_back(n);
                if (--mp[n] == 0) {
                    mp.erase(n);
                    if (mp.empty()) break;
                }
            }
        }
        return res;
    }
};
