#define ISDIGIT(c) (c<='9'&&c>='0')
class Solution {
public:
    bool isNumber(string s) {
        // remove leading and trailing blank
        int len=s.length();
        while(len>0 && s[len-1]==' ') --len;
        if(!len)    return false;
        int i=0;
        while(s[i]==' ') ++i;
        
        bool fraction=false;
        bool start=true;
        bool number=false;
        bool e=false;
        for(; i<len; ++i) {
            if(start && s[i] == 'e')    return false;
            // can only occur when start or just after e
            if((s[i] == '+' || s[i] == '-') && (!start && i && s[i-1]!='e'))
                return false;
            // acceptable char set
            start=false;
            if(!ISDIGIT(s[i]) && s[i]!='-' && s[i]!='+' && s[i]!='.' && s[i]!='e')
                return false;
            // judge number
            if(ISDIGIT(s[i])) {
                number=true;
                continue;
            }
            // no sign or dot can be in fraction part
            if(fraction && (s[i] == '+' || s[i]=='-' || s[i]=='.'))    
                return false;
            // no dot or e can be after e
            if(e && (s[i] == '.' || s[i] == 'e'))    
                return false;
                
            if(s[i]=='e') {
                // at least one number should befor e
                if(!number) return false;
                e=true;
                // re check number and fraction
                number=false;
                fraction=false;
            }
            // no dot after e
            if(s[i]=='.') {
                if(e)   return false;
                fraction=true;
            }
            
        }
        return number;
    }
};