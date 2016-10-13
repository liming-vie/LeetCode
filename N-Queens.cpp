class Solution {
public:
    bool is[50][50]={};
    bool col[50]={};
    bool rd[100]={};
    bool ld[100]={};
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        func(0,n);
        return res;
    }
    
    void func(int vi,int &n){
        if(vi==n){
            vector<string> tmp;
            for(int i=0; i<n; ++i){
                string str="";
                for(int j=0; j<n; ++j){
                    if(is[i][j])    str += 'Q';
                    else    str += '.';
                }
                tmp.push_back(str);
            }
            res.push_back(tmp);
            return;
        }
        
        int i=vi;
        for(int j=0; j<n; ++j){
            if(col[j] || rd[i+j] || ld[i+n-j-1] || is[i][j])
                continue;
            col[j]=true;
            ld[i+n-j-1]=true;
            rd[i+j]=true;
            is[i][j]=true;
            
            func(vi+1,n);
            
            is[i][j]=false;
            ld[i+n-j-1]=false;
            rd[i+j]=false;
            col[j]=false;   
        }
    }
};