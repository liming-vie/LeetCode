class Solution {
public:
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visit;
    int n, m;
    int res;
    
    void search(const vector<vector<char>>& grid, int vi, int vj, bool first) {
        if (vi<0 || vj<0 || vi>=n || vj>=m || visit[vi][vj] || grid[vi][vj] == '0')    return;
        
        visit[vi][vj] = true;
        if (first)  ++res;
        
        for (int i=0; i<4; ++i) {
            search(grid, vi+d[i][0], vj+d[i][1], false);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        if (!n) return 0;
        m=grid[0].size();
        if (!m) return 0;
    
        res = 0;
        visit = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m ; ++j) {
                search(grid, i, j, true);
            }
        }
        
        return res;
    }
};