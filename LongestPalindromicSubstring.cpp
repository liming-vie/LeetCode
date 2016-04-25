class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len < 2) return s;
        bool is[1000][1000];
        for(int i=0; i<len; ++i) {
            is[i][i] = true;
        }
        int res=1,res_b=0;
        for(int i=1; i<len; ++i) {
            is[i-1][i] = (s[i] == s[i-1]) ? res=2, res_b=i-1, true: false;
        }
        
        int upperi, j;
        for(int l=3; l<=len; ++l) {
            upperi = len - l;
            for(int i=0; i<=upperi; ++i) {
                j=i+l-1;
                is[i][j] = ((s[i] == s[j]) && is[i+1][j-1]) ? res=l,res_b=i,true : false;
            }
        }
        return s.substr(res_b, res);
    }
};