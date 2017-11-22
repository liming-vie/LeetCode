class Solution {
public:
    int d[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    
    void gameOfLife(vector<vector<int>>& board) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                int count=0;
                for (int t=0; t<8; ++t) {
                    int vi=i+d[t][0], vj=j+d[t][1];
                    if (vi<0 || vj<0 || vi==board.size() || vj==board[i].size())
                        continue;
                    count += (board[vi][vj]&1);
                }
                if (board[i][j]) {
                    if (count < 2 || count > 3) 
                        board[i][j] = 3;
                } else if (count == 3) {
                    board[i][j] = 2;
                }
            }
        }
        
        int rep[4] = {0, 1, 1, 0};
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                board[i][j] = rep[board[i][j]];
            }
        }
    } 
};