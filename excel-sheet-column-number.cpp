class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for (const char&c : s) {
            res*=26;
            res += (c-'A')+1;            
        }
        return res;
    }
};