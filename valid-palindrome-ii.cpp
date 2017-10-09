class Solution {
public:
    bool valid(const string& s, bool first) {
        int i=0, j=s.length()-1;
        while (i<j) {
            if (s[i] == s[j]) {
                ++i, --j;
            } else {
                return first && (valid(s.substr(i, j-i), false) || valid(s.substr(i+1, j-i), false));
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return valid(s, true);
    }
};