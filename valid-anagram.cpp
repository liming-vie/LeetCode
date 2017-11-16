class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> count;
        for (int i=0; i<s.length(); ++i) {
            ++count[s[i]];
            --count[t[i]];
        }
        for (const auto kv : count) {
            if (kv.second)
                return false;
        }
        return true;
    }
};