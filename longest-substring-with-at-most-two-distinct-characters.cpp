class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> count;
        int start=0, res=0;
        int cur_size=0;
        for (int i=0; i<s.length(); ++i) {
            if (count[s[i]]==0) {
                if (cur_size==2) {
                    res = max(i-start, res);
                    while (--count[s[start++]]);
                } else ++cur_size;
            }
            ++count[s[i]];
        }
        return max((int)s.length()-start, res);
    }
};