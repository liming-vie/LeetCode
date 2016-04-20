class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int pos[260]={0};
        int res=0,tmp;
        int begin=0;
        for(int i=0; i<len; ++i) {
            if(pos[s[i]] > begin) {
                tmp = i-begin;
                res = tmp>res?tmp:res;
                begin = pos[s[i]];
            }
            pos[s[i]] = i + 1;
        }
        tmp = len-begin;
        res = tmp>res?tmp:res;
        return res;
    }
};