class Solution {
public:
    vector<string> res;
    void func(int l, int r, string cur) {
        if(l==0 && r==0) res.push_back(cur);
        else if(l<=r) {
            if(l>0) func(l-1, r, cur+"(");   
            if(r>0) func(l, r-1, cur+")");
        }
    }
    vector<string> generateParenthesis(int n) {
       func(n,n,"");
       return res;
    }
};