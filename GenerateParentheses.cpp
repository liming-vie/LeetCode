class Solution {
public:

    vector<string> res;
    
    void func(int l, int r, string tmp){
        if(l==0 && r==0){
            res.push_back(tmp);
        }
        if(l>0){
            func(l-1,r,tmp+"(");
        }
        if(r>0 && r>l)
            func(l,r-1,tmp+")");
    }

    vector<string> generateParenthesis(int n) {
        func(n,n,"");
        return res;
    }
};