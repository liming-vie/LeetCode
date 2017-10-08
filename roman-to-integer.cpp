class Solution {
public:
    inline int GetNumber(char c){
        switch(c){
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int len=s.length();
        int res=0;
        for(int i=0; i<len-1; ++i) {
            int tmp=GetNumber(s[i]);
            if(tmp < GetNumber(s[i+1])) res -= tmp;
            else    res += tmp;
        }
        res += GetNumber(s[len-1]);
        return res;
    }
};