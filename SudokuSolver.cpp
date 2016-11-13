class Solution {
public:
    bool check(vector<vector<char> >&board,int x,int y){
        bool col[9],row[9];
            memset(col,0,sizeof(col));
            memset(row,0,sizeof(row));
        for(int i=0; i<9; ++i){
                if(board[x][i] != '.'){
                    if(row[board[x][i]-'1'])    return false;
                    row[board[x][i]-'1']=true;
                }
                if(board[i][y]!='.'){
                    if(col[board[i][y]-'1'])    return false;
                    col[board[i][y]-'1']=true;
                }
        }
        
        memset(col,0,sizeof(col));
        int t1=x-x%3,t2=y-y%3;
        for(int i=t1;i<t1+3; ++i)
            for(int j=t2; j<t2+3; ++j){
                if(board[i][j]!='.'){
                    if(col[board[i][j]-'1'])    return false;
                    col[board[i][j]-'1']=true;
                }
            }
        return true;    
    }
    
    bool fill(int i,int j, vector<vector<char> > &board){
        if(j==9){
            i+=1;
            if(i==9)    return true;
            j=0;
        }
        
        if(board[i][j]!='.')    return fill(i,j+1,board);
        
        for(int k=1; k<10; ++k){
            board[i][j]='0'+k;
            
            if(check(board,i,j) && fill(i,j+1,board))   return true;
            
            board[i][j]='.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        fill(0,0,board);
    }
};