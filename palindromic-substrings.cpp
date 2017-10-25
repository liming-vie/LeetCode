class Solution {
public:
    int countSubstrings(string s) {
        int len=s.length();
        int res=0;
        for (int i=0; i<len; ++i) {
            res += valid(s, i, i) + valid(s, i, i+1);
        }
        return res;
    }
    
    int valid(const string& s, int l, int r) {
        int res=0;
        while (l>=0 && r<s.length() && s[l]==s[r]) {
            ++res; --l; ++r;
        }
        return res;
    }
};