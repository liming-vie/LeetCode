class Solution {
public:
    bool is[500][500]={};
    int m,n,len;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        if(m!=0)    n=board[0].size();
        len=word.length();
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j){
                if(func(i,j,0,board,word)) 
                    return true;
            }
        return false;
    }
    
    bool func(int vi,int vj, int index, vector<vector<char>>& board, string word){
        if(index==len)    return true;
        
        if(vi<0||vj<0||vi==m||vj==n||is[vi][vj]||board[vi][vj]!=word[index])  return false;
        
        is[vi][vj]=true;
        
        int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0; i<4; ++i){
            int x=vi+d[i][0],y=vj+d[i][1];
            
            if(func(x,y,index+1,board,word))
                return true;
        }
        
        is[vi][vj]=false;
        
        return false;
    }
};