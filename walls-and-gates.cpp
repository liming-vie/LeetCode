#define INF 2147483647

class Solution {
    struct Room {
        Room(int x, int y, int v) : x(x), y(y), val(v) {}
        int x, y;
        int val;
    };
        
public:
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        int n=rooms.size(); if (!n) return;
        int m=rooms[0].size(); if (!m) return;
        
        queue<Room> q;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!rooms[i][j]) {
                    q.push(Room(i,j,0));
                }
            }
        }
        
        while(!q.empty()) {
            const auto& room = q.front();
            for (int i=0; i<4; ++i) {
                int vi=room.x + d[i][0];
                int vj=room.y + d[i][1];
                if (vi < 0 || vi == n || vj < 0 || vj == m || rooms[vi][vj] == -1 || rooms[vi][vj] < INF)  continue;
                rooms[vi][vj] = room.val + 1;
                q.push(Room(vi,vj,room.val+1));
            }
            q.pop();
        }
    }
};