class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (const string& word : wordDict) {
            st.insert(word);
        }
        
        int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        
        for (int i=1; i<=len; ++i) {
            for (int j=i; j>0; --j) {
                if (dp[j-1] && st.find(s.substr(j-1, i-j+1))!=st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[len];
    }
};