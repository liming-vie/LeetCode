class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        int len=s.length();
        for(int i=0; i<len; ++i){
            switch(s[i]){
                case '(':   
                    v.push_back('('); break;
                case ')':  
                    if(v.size()==0 || v.back()!='(')    return false;
                    v.pop_back();      break;
                case '{':
                    v.push_back('{'); break;
                case '}':
                    if(v.size()==0 || v.back()!='{')    return false;
                    v.pop_back();      break;
                case '[':
                    v.push_back('['); break;
                case ']':
                    if(v.size()==0 || v.back()!='[')    return false;
                        v.pop_back();      break;
            }
        }
        if(v.size()>0)    return false;
        return true;
    }
};