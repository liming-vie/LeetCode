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
            ++count[cur];
        }
        
        for (const auto &kv : count) {
            if (kv.second<=1)   continue;
            string str;
            int key=kv.first;
            for (int i=0; i<10; ++i) {
                str = val2str[key&3] + str;
                key>>=2;
            }
            res.push_back(str);
        }
         
        return res;
    }
};