class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto str:strs) {
            string s=str;
            sort(str.begin(), str.end());
            if(mp.find(str)==mp.end()) {
                mp[str]=vector<string>();
            }
            mp[str].push_back(s);
        }
        vector<vector<string>> res;
        for(auto kp:mp) {
            res.push_back(kp.second);
        }
        return res;
    }
};