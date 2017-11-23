class Solution {
public:
    unordered_map<char, string> mp;
    unordered_set<string> st;
    
    bool dps(const string& pattern, const string& str, int pi, int si) {
        if (pi==pattern.length())   return si==str.length();
        if (si==str.length())   return pi==pattern.length();
        
        char p=pattern[pi];
        if (mp.find(p)!=mp.end()) {
            const auto& prev = mp[p];
            if (str.substr(si, prev.length()) != prev)
                return false;
            return dps(pattern, str, pi+1, si+prev.length());
        }
        
        for (int i=si; i<str.length(); ++i) {
            const auto& part = str.substr(si, i-si+1);
            if (st.find(part)!=st.end())
                continue;
            st.insert(part);
            mp[p] = part;
            if (dps(pattern, str, pi+1, si+part.length()))
                return true;
            st.erase(part);
        }
        mp.erase(p);
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        return dps(pattern, str, 0, 0);
    }
};