class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n=strs.size();
        if(n==0)    return "";
        if(n==1)    return strs[0];
        
        int minl=strs[0].length();
        vector<string>::iterator i=strs.begin();
        for(++i; i!=strs.end(); ++i)
            if((*i).length()<minl)  minl = (*i).length();
        
        if(minl==0) return "";
        
        char c;
        int l;
        for(l=0; l<minl; ++l){
            i=strs.begin();
            c=(*i)[l];
            for(++i; i!=strs.end(); ++i)
                if((*i)[l] != c)
                    return (*i).substr(0,l);
        }
        return strs[0].substr(0,minl);
    }
};