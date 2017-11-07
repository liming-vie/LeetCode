class Solution {
public:
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length()<=10)  return res;
       
        char val2str[4]={'A','C','G','T'};
        unordered_map<char, int> str2val;
        for (int i=0; i<4; ++i) str2val[val2str[i]]=i;
        
        unordered_map<int, int> count;
        int mask=0xFFFFF;
        int cur=0;
        for (int i=0; i<9; ++i)
            cur = (str2val[s[i]] | (cur<<2));
        
        for (int i=9; i<s.length(); ++i) {
            cur = ((str2val[s[i]] | (cur<<2)) & mask);
            if (++count[cur]==2) {
                res.push_back(s.substr(i-9, 10));
            }
        }
        
        return res;
    }
};