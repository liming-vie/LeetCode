class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int shortestDistance(vector<vector<int>>& grid) {
        int n=grid.size(); if (!n)  return -1;
        int m=grid[0].size();
        auto dist = grid;
        int count=0, res;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] != 1)    continue;
                res=-1;
                
                queue<pair<int, int>> q;
                q.emplace(i, j);
                q.emplace(-1, -1);
                
                int step = 1;
                while (!q.empty()) {
                    const auto &cur = q.front();
                    if (cur.first==-1) {
                        ++step;
                        if (q.size()>1) q.emplace(-1,-1);
                    } 
                    else {
                        for (int k=0; k<4; ++k) {
                            int vi=cur.first+d[k][0], vj=cur.second+d[k][1];
                            if (vi<0 || vi==n || vj<0 || vj==m || grid[vi][vj]!=count)
                                continue;
                            q.emplace(vi,vj);
                            
                            --grid[vi][vj];
                            dist[vi][vj] += step;
                            if (res < 0 || res>dist[vi][vj])
                                res = dist[vi][vj];
                        }   
                    }
                    
                    q.pop();
                }
                
                --count;
            }
        }
        return res;
    }
};