class Solution {
public:
    vector<string> res;
    
    string getstr(char c){
        switch(c){
        case '1': return "";
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        case '0': return " ";
        case '*': return "+";
        case '#': return "";
        }
        return "";
    }
    
    void getres(int vi, int len, string &str, string tmp){
        if(vi==len){
            res.push_back(tmp);
            return;
        }
        
        string s=getstr(str[vi]);
        int l=s.length();
        if(l==0){
            getres(vi+1,len,str,tmp);
            return;
        }    
        
        for(int i=0; i<l; ++i)
            getres(vi+1,len,str,tmp+s[i]);
    }
    
    vector<string> letterCombinations(string digits) {
        int len=digits.length();
        if(len==0)  return res;
        
        getres(0,len,digits,"");
        
        return res;
    }
};