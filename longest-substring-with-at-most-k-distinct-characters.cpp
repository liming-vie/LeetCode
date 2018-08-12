class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k==0)   return 0;
        unordered_map<char, int> mp;
        int len=s.length();
        int start = 0, res = 0;
        for (int i=0; i<len; ++i) {
            char c = s[i];
            if (mp.find(c)==mp.end() && mp.size()==k) {
                for (; start < i ; ++start) {
                    if (--mp[s[start]] == 0) {
                        mp.erase(s[start++]);
                        break;
                    }
                }
            }
            ++mp[c];
            res = max(i-start+1, res);
        }
        return max(len-start, res);
    }
};
