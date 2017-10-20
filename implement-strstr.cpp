class Solution {
public:
    vector<int> next;
    
    void func(string pattern) {
        int len=pattern.length();
        next.resize(len+1);
        next[0]=-1;
        int k=-1,j=0;
        while(j<len) {
            if(k<0 || pattern[j]==pattern[k]) {
                ++j,++k;
                next[j]=(pattern[j]==pattern[k]?next[k]:k);
            }
            else k=next[k];
        }
    }

    int strStr(string haystack, string needle) {
        func(needle);
        int l1=haystack.length(), l2=needle.size();
        int i=0, j=0;
        while(i<l1 && j<l2) {
            if(j<0||haystack[i]==needle[j]) ++i,++j;
            else    j=next[j];
        }
        return j==l2 ? i-j : -1;
    }
};