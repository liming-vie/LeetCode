class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int last=0, res=0, len=s.length();
        for(int i=0; i<len; ++i) {
            if(mp.find(s[i])!=mp.end() && mp[s[i]] >= last) {
                last=mp[s[i]]+1;
            }
            mp[s[i]]=i;
            int tmp=i-last+1;
            res=tmp>res?tmp:res;
        }
        return res;
    }
};