class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int start=0, res=0;
        for (int i=0; i<s.length(); ++i) {
            if (mp.find(s[i])==mp.end() && mp.size()==2) {
                while(start<i && --mp[s[start++]]);
                mp.erase(s[start-1]);
            }
            ++mp[s[i]];
            res=max(res, i-start+1);
        }
        return max(res, (int)s.length()-start);
    }
};
