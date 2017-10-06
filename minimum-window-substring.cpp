class Solution {
public:
    string minWindow(string s, string t) {
        int need[150]={0};
        for(auto c : t)
            ++need[c];
            
        int slen=s.length(), tlen=t.length();
        int count[150]={0};
        int tot=0, begin=0;
        int resl=slen+1, resb;
        for(int i=0; i<slen; ++i) {
            if(need[s[i]]==0)   continue;
            
            if(++count[s[i]] <= need[s[i]]) ++tot;
            
            if(tot>=tlen) {
                for(; begin<=i; ++begin) {
                    if(need[s[begin]]==0)   continue;
                    if(count[s[begin]] > need[s[begin]]) --count[s[begin]];
                    else    break;
                }
                
                int tmp=i-begin+1;
                if(tmp<resl) {
                    resl=tmp;
                    resb=begin;
                }
            }
        }
        
        if(resl==slen+1)    return "";
        return s.substr(resb, resl);
    }
};