class Solution {
public:
    bool match(const char*s,const char*p) {
        if(*p=='\0')    return *s == '\0';
        if(*(p+1) != '*') {
            return (*p == *s || (*p=='.' && *s!='\0')) && match(s+1,p+1);
        }
        while(*p == *s || (*p=='.' && *s!='\0')) {
            if(match(s,p+2))    return true;
            ++s;
        }
        return match(s,p+2);
    }
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
};