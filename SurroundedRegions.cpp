#define MP(a,b) make_pair(a,b)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=n==0?0:board[0].size();
        if(!n||!m)  return;
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i) {
            if(board[i][0]=='O')    q.push(MP(i,0));
            if(board[i][m-1]=='O')  q.push(MP(i,m-1));
        }
        for(int i=1; i<m-1; ++i) {
            if(board[0][i]=='O')    q.push(MP(0,i));
            if(board[n-1][i]=='O')  q.push(MP(n-1,i));
        }
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            auto p=q.front();
            q.pop();
            board[p.first][p.second]='Y';
            for(int i=0; i<4; ++i) {
                int vi=p.first+d[i][0], vj=p.second+d[i][1];
                if(vi<0 || vj<0 || vi>=n || vj>=m || board[vi][vj]!='O')    continue;
                q.push(MP(vi,vj));
            }
        }
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                switch(board[i][j]) {
                    case 'Y':
                        board[i][j]='O';
                        break;
                    case 'O':
                        board[i][j]='X';
                        break;
                }
            }
    }
};