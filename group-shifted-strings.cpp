class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (const auto& str : strings) {
            if (str.length()==0) {
                mp[str].push_back(str);
            } else {
                int diff = str[0]-'a';
                string tmp;
                for (char c : str) {
                    tmp += ((c+26-diff)%26)+'a';
                }
                mp[tmp].push_back(str);
            }
        }
        vector<vector<string>> res;
        
        for (const auto& kv : mp) {
            res.push_back(kv.second);
        }
        return res;
    }
};