class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st;
        for (const auto c:s) st.insert(c);
        
        int res=0;
        for (const auto c:st) {
            res = max(res, func(s, c, k));
        }
        return res;
    }
    
    int func(string s, char c, int k) {
        int start=0, res=0, count=0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] != c) {
                ++count;
            }
            if (count>k) {
                while (s[start++]==c);
                --count;
            }
            res = max(i-start+1, res);
        }
        return max((int)s.length()-start, res);
    }
};
