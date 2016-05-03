class Solution {
public:
    int*next;
    void computeNext(string&pattern, int begin) {
        int i=0;
        int j=-1;
        int idx=0;
        next[0]=-1;
        int len=pattern.length() - begin;
        while(i<len) {
            while(j!=-1 && pattern[j] != pattern[idx])
                j=next[j];
            next[++i] = ++j;
            ++idx;
        }
    }
    int func(string&s, string&p, int begin_p) {
        int i=0,j=0;
        int l1=s.length(), l2=p.length();
        int res=0;
        while(i<l1 && j < l2) {
            if(j==-1 || s[i]==p[j+begin_p]) {
                ++i;
                ++j;
                res = res > j ? res : j;
            }
            else {
                j=next[j];
            }
        }
        return res;
    }
    string longestPalindrome(string s) {
        int len=s.length();
        if(len<2)   return s;
        
        next = new int[len+1];
        int res=0;
        int begin=0;
        string rev = s;
        reverse(rev.begin(), rev.end());
        for(int i=0; i<len; ++i) {
            computeNext(rev, i);
            int tmp=func(s,rev, i);
            if(tmp>res) {
                res=tmp;
                begin=i;
            }
            if(len - i < res) break;
        }
        return rev.substr(begin, res);
    }
};