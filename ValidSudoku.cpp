class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool col[10],row[10];
        for(int i=0; i<9; ++i){
            memset(col,0,sizeof(col));
            memset(row,0,sizeof(row));
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.'){
                    if(col[board[i][j]-'0'])    return false;
                    col[board[i][j]-'0']=true;
                }
                if(board[j][i]!='.'){
                    if(row[board[j][i]-'0'])    return false;
                    row[board[j][i]-'0']=true;
                }
            }
        }
        for(int i=0; i<9; i+=3)
            for(int j=0; j<9; j+=3){
                memset(col,0,sizeof(col));
                for(int k=0; k<3; ++k)
                    for(int t=0; t<3; ++t)
                        if(board[i+k][j+t]!='.'){
                            if(col[board[i+k][j+t]-'0'])    return false;
                            col[board[i+k][j+t]-'0']=true;
                        }
                        
            }
        return true;    
    }
};