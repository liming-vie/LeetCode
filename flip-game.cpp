class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i=1; i<s.length(); ++i) {
            if (s[i]=='+'&&s[i-1]=='+') {
                string t=s;
                t[i-1]=t[i]='-';
                res.push_back(t);
            }
        }
        return res;
    }
};