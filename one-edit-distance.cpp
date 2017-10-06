class Solution {
public:    
    bool isOneEditDistance(string s, string t) {
        int sl=s.length(), tl=t.length();
        if (sl == tl) {
            int count = 0;
            for (int i=0; i<sl; ++i) {
                if (s[i] != t[i]) {
                    if (++count > 1) {
                        return false;
                    }
                }
            }
            return count == 1;
        }
        
        if (abs(sl - tl) != 1) {
            return false;
        }
        
        int i=0, j=0;
        while (i<sl && j<tl) {
            if (s[i] != t[j]) {
                if (s.substr(i+1, sl-i-1) == t.substr(j, tl-j) || s.substr(i, sl-i) == t.substr(j+1, tl-j-1)) {
                    return true;
                }
                return false;
            }
            ++i, ++j;
        }
        return true;
    }
};