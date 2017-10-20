class Solution {
public:
    vector<int> getNext(const string& p) {
        int len=p.length();
        int k=-1;
        vector<int> next(len);
        next[0] = -1;
        int i=0;
        while (i<len) {
            if (k>=0 && p[k]!=p[i])
                k=next[k];
            if (++i >= len) break;
            ++k;
            next[i] = (p[k] == p[i]) ? next[k] : k;
        }
        return next;
    }
    
    int strStr(string haystack, string needle) {
        int l1=haystack.length(), l2=needle.length();
        if (l1 < l2)    return -1;
        if (l2==0)  return 0;
        
        const auto& next = getNext(needle);
        int i=0, j=0;
        
        while (i<l1 && j<l2) {
            if (j==-1 || haystack[i]!=needle[j]) {
                j=next[j];
            }
            ++i;
            ++j;
        }
        return j==l2 ? (i-l2) : -1;
    }
};