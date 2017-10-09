class Solution {
public:
    string countAndSay(int n) {
        if(n<=0)    return "";
        string s1="1", s2="";
        for(int i=1; i<n; ++i) {
            int count=1;
            int len=s1.length();
            for(int i=1; i<=len; ++i) {
                if(i<len && s1[i] == s1[i-1])
                    ++count;
                else {
                    s2 += (count+'0');
                    s2 += s1[i-1];
                    count=1;
                }
            }
            s1=s2;
            s2="";
        }
        return s1;
    }
};