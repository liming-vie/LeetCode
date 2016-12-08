class Solution {
public:
    int m, n;
    vector<vector<bool>> use;
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool search(vector<vector<char>>&board, string& word, int vi, int vj, int len) {
        if(len==word.length())  return true;
        
        if (vi<0 || vj<0 || vi==m || vj==n || use[vi][vj] || board[vi][vj]!=word[len])  return false;
        
        use[vi][vj]=true;
        for(int i=0; i<4; ++i) {
            if(search(board, word, vi+d[i][0], vj+d[i][1], len+1))
                return true;
        }
        use[vi][vj]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board.size()==0?0:board[0].size();
        if(!m || !n)    return false;
        
        use=vector<vector<bool>>(m, vector<bool>(n));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(word[0]==board[i][j] && search(board, word, i, j, 0)) 
                    return true;
            }
        }
        return false;
    }
};