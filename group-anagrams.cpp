class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            if (mp.find(s) == mp.end()) {
                mp[s] = vector<string>({str});
            } else {
                mp[s].push_back(str);
            }
        }
        
        vector<vector<string>> res;
        for (const auto& kv : mp) {
            res.push_back(kv.second);
        }
        return res;
    }
};