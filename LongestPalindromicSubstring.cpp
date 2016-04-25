class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        int res=0,tmp;
        int rl;
        for(int i=0; i<len; ++i){
            int l=i-1,r=i+1;
            tmp=1;
            while(l>=0 && r<len && s[l]==s[r]){
               tmp+=2;
               l--;
               r++;
            }  
            if(tmp>res){
                res=tmp;
                rl = l+1;
            }  
            l=i-1;
            r=i;
            tmp=0;
            while(l>=0 && r<len && s[l]==s[r]){
                tmp+=2;
                l--;
                r++;
            }
            if(tmp>res){
                res=tmp;
                rl=l+1;
            } 
        }
        return s.substr(rl,res);
    }
};