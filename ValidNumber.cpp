class Solution {
public:
    bool e=false;   
    bool isNumber(string s) {
        int len=s.length();
        for(int i=len-1; i>=0; --i){
            if(s[i]==' ')
                --len;
            else    break;
        }
        if(len<=0)    return false;
        int i=0;
        while(s[i]==' ')    ++i;
        bool dot=false;
        bool number=false;
        bool start=false;
        for( ;i<len;++i){
            if(s[i]>='0' && s[i]<='9')  number=true;
            if(start && s[i]!='e' && s[i]!='.' && (s[i]<'0' || s[i]>'9'))   return false;
            
            if(!start){
                if(!(s[i]=='.'||s[i]=='-' || s[i]=='+' || (s[i]>='0' && s[i]<='9')))
                    return false;
                start=true;
            }
            
            if(s[i]=='e'){
                if(e)   return false;
                e=true;
                return number && isNumber(s.substr(i+1,len-i-1));
            }  
            if(s[i]=='.'){
                if(dot || e) return false;
                dot=true;
                continue;
            }
        }
        if(number)
            return true;
        return false;
    }
};