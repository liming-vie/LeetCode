class Solution {
public:
    void reverseWords(string &s) {
        int len=s.length(), idx=0;
        for (int i=0; i<len; ++i) {
            if (s[i]!=' ')  s[idx++]=s[i];
            else if (i && s[i-1]!=' ')  s[idx++]=s[i];
        }
        len = idx;
        while (len && s[len-1]==' ') --len;
        s.resize(len);
        
        if (!len)    return;
        
        int start=0;
        for (int i=0; i<=len; ++i) {
            if (i==len || s[i]==' ') {
                reverse(s.begin()+start, s.begin()+i);
                start=i+1;
            }
        }
        reverse(s.begin(), s.end());
    }
};