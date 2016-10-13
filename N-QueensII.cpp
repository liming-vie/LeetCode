class Solution {
public:
    bool is[50][50]={};
    bool col[50]={};
    bool rd[100]={};
    bool ld[100]={};
    int res=0;

    int totalNQueens(int n) {
        func(0,n);
        return res;
    }
    
    void func(int vi,int &n){
        if(vi==n){;
            ++res;
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