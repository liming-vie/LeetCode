class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.length();
        if (len != t.length())   return false;
        
        unordered_map<char, char> s2t;
        unordered_set<char> t2s;
        for (int i=0; i<len; ++i) {
            if (s2t.find(s[i])==s2t.end()) {
                if (t2s.find(t[i])!=t2s.end())
                    return false;
                s2t[s[i]]=t[i];
                t2s.insert(t[i]);
            } else if (s2t[s[i]]!=t[i])
                return false;
        }
        
        return true;
    }
};