class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pl=pattern.length(), sl=str.length();
        unordered_set<char> pst;
        unordered_map<string, char> s2p;
        int si=0, pi;
        for (pi=0; pi<pl && si<sl; ++pi) {
            int idx = str.find(' ', si);
            idx = idx==-1 ? sl : idx;
            const auto& part = str.substr(si, idx-si);
            if (pst.find(pattern[pi])==pst.end()) {
                if (s2p.find(part)!=s2p.end())
                    return false;
                s2p[part] = pattern[pi];
                pst.insert(pattern[pi]);
            } else if (s2p[part]!=pattern[pi]) {
                return false;
            }
            si = idx+1;
        }
        return pi==pl && si>=sl;
    }
};