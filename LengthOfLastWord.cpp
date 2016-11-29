class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length();
        int res=-1;
        for(int i=len-1; i>=0; --i){
            if(s[i]==' '){
                if(res==-1) continue;
                break;
            }
            if(res==-1) res=0;
            ++res;
        }
        if(res==-1) return 0;
        return res;
    }
};