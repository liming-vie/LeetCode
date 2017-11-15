class Solution {
public:
    vector<int> compute(const string& p) {
        int len=p.length();
        vector<int> next(len+1);
        next[0]=-1;
        int k=-1;
        int i=0;
        while (i<len) {
            while (k>=0 && p[i] != p[k]) {
                k = next[k];
            }
            next[++i]=++k;
        }
        
        return next;
    }
    
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        
        string p = s + "#" + r;
        const auto& next = compute(p);
        
        return r.substr(0, s.length()-next[p.length()-1]-1) + s;
    }
};