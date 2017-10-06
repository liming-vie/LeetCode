class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())    return "";
        
        unordered_map<char, int> need;
        for(auto c:t) {
            ++need[c];
        }
        
        int resl = -1, ress = -1;
        int start=0, tot=0;
        unordered_map<char, int> count;
        for (int i=0; i<s.length(); ++i) {
            if (need.find(s[i]) == need.end()) {
                continue;
            }
            
            if (++count[s[i]] <= need[s[i]]) ++tot;
            
            if (tot >= t.length()) {
                for (; start<i; ++start) {
                    if (need.find(s[start]) == need.end()) {
                        continue;
                    }
                    else if (count[s[start]] > need[s[start]]) {
                        --count[s[start]];
                    }
                    else {
                        break;
                    }
                }
                
                int tmp = i - start + 1;
                if (resl == -1 || resl > tmp) {
                    resl = tmp;
                    ress = start;
                }
            }
        }
        
        if (resl == -1) return "";
        return s.substr(ress, resl);
    }
};