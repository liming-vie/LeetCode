#define INF 2147483647

class Solution {
public:
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int search(const vector<vector<int>>& rooms, vector<vector<bool>>& visit, int vi, int vj) {
        if (vi<0 || vi==rooms.size() || vj<0 || vj==rooms[0].size() || rooms[vi][vj] == -1)    return INF;
        if (rooms[vi][vj]>=0 && rooms[vi][vj]<INF) return rooms[vi][vj];
        if (visit[vi][vj])  return INF;
        
        visit[vi][vj] = true;
        int tmp = INF;
        for (int i=0; i<4; ++i) {
            tmp = min(search(rooms, visit, vi+d[i][0], vj+d[i][1]), tmp);
        }
        if (tmp < INF)  ++tmp;
        visit[vi][vj] = false;
        return tmp;
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n=rooms.size(); if (!n) return;
        int m=rooms[0].size(); if (!m) return;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (rooms[i][j] <= 0) continue;
                rooms[i][j] = search(rooms, visit, i, j);
                visit[i][j] = true;
            }
        }
    }
};