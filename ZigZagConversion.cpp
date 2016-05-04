class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        int len=s.length();
        int max = (numRows << 1) - 2;
        int d;
        int j=0;
        stringstream ss;
        for(int i=0; i<numRows; ++i) {
            d = max - (i<<1);
            d = (d==0 ? max : d);
            j=i;
            while(j<len) {
                ss<<s[j];
                j+=d;
                d = (d==max?max:max-d);
            }
        }
        return ss.str();
    }
};