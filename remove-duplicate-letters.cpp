class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        
        int count[26]={0};
        for (char c:s) {
            ++count[c-'a'];
        }
        int pos=0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] < s[pos]) pos=i;
            if (--count[s[i]-'a']==0)
                break;
        }
        return s[pos] + removeDuplicateLetters(removeChar(s.substr(pos+1), s[pos]));
    }
    
    string removeChar(const string& s, char c) {
        stringstream ss;
        for (char t : s) {
            if (t==c) continue;
            ss<<t;
        }
        return ss.str();
    }
};