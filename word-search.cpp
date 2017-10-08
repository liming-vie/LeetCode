class Solution {
public:
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool search(const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visit, int vi, int vj, int wi) {
        if (wi == word.length()) return true;
        if (vi<0 || vi==board.size() || vj<0 || vj==board[0].size() || visit[vi][vj] || board[vi][vj]!=word[wi])    return false;
        
        visit[vi][vj] = true;
        for (int i=0; i<4; ++i) {
            if (search(board, word, visit, vi+d[i][0], vj+d[i][1], wi+1))   return true;
        }
        visit[vi][vj] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();     if (!n) return false;
        int m=board[0].size();  if (!m) return false;
        if (n*m < word.length())        return false;
        
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (search(board, word, visit, i, j, 0)) 
                    return true;
            }
        }
        return false;
    }
};