class Solution {
public:
    int val(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int res=0, len=s.length(), v;
        for (int i=0; i<len; ++i) {
            v = val(s[i]);
            if (i+1<len && v < val(s[i+1])) {
                res -= v;
            } else res += v;
        }
        return res;
    }
};