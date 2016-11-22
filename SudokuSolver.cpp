class Solution {
public:
    bool rows[9][10]={};
    bool cols[9][10]={};
    // check each 3*3 array
    bool little[9][10]={};
    
    bool func(vector<vector<char>>& board, int vi, int vj) {
        if(vi==9)   return true;
        if(vj==9)   return func(board, vi+1, 0);
        if(board[vi][vj] != '.')    return func(board, vi, vj+1);
            
        int t=vi/3*3+vj/3;
        for(int i=1; i<=9; ++i) {
            if(rows[vi][i] || cols[vj][i] || little[t][i])
                continue;
            rows[vi][i] = cols[vj][i] = little[t][i] = true;
            board[vi][vj]='0'+i;
            if (func(board,vi,vj+1))
                return true;
            rows[vi][i] = cols[vj][i] = little[t][i] = false;
            board[vi][vj]='.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // pre-process 
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.')  continue;
                int t=board[i][j]-'0';
                rows[i][t]=cols[j][t]=little[i/3*3+j/3][t]=true;
            }
        func(board,0,0);
    }
};