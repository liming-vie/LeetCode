class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        map<int, unordered_set<string>> mp;
        for (const auto& word : words) {
            mp[word.length()].insert(word);
        }
        
        vector<string> res;
        for (const auto& word : words) {
            if (!word.length()) continue;
            vector<bool> dp(word.length()+1, false);
            dp[0]=true;
            for (int i=0; i<=word.length(); ++i) {
                if (!dp[i]) continue;
                for (const auto& kv : mp) {
                    if (kv.first==word.length() || i+kv.first>word.length())
                        break;
                    if (kv.second.find(word.substr(i, kv.first))!=kv.second.end()) {
                        dp[i+kv.first] = true;
                    }
                }
                if (dp[word.length()]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};