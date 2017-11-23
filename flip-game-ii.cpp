class Solution {
public:
    unordered_map<string, int> win[2];
    
    bool round(string s, bool start) {
        if (win[start][s])  return win[start][s]&1;
        
        bool last=s[0]=='+', cur;
        for (int i=1; i<s.length(); ++i) {
            cur=s[i]=='+';
            if (last && cur) {
                s[i-1]=s[i]='-';
                if (!round(s, !start)) {
                    win[start][s]=3;
                    return true;
                }
                s[i-1]=s[i]='+';
            }
            last=cur;
        }
        win[start][s]=2;
        return false;
    }
    
    bool canWin(string s) {
        if (s.length()<2)   return false;
        return round(s, true);
    }
};