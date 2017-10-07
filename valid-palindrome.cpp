class Solution {
public:
    inline bool valid(char c) {
        return ((c>='a' && c<='z') || (c>='A'&&c<='Z') || (c>='0' && c<='9'));
    }
    
    inline char lower(char c) {
        if (c>='A'&&c<='Z') return c+'a'-'A';
        return c;
    }
    
    bool isPalindrome(string s) {
        int i=0, j=s.length() - 1;
        while (i<j) {
            if (!valid(s[i])) ++i;
            else if (!valid(s[j])) --j;
            else if (lower(s[i]) != lower(s[j])) {
                return false;
            } else {
                ++i; --j;   
            }
        }
        return true;
    }
};