#define MK(x, y) make_pair(x, y)

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(); if (!n) return 0;
        int m=heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int i=0; i<n; ++i) {
            visit[i][0]=visit[i][m-1]=true;
            pq.push(MK(heightMap[i][0], (i*m)));
            pq.push(MK(heightMap[i][m-1], (i*m+m-1)));
        }
        for (int i=0; i<m; ++i) {
            visit[0][i]=visit[n-1][i]=true;
            pq.push(MK(heightMap[0][i], i));
            pq.push(MK(heightMap[n-1][i], ((n-1)*m+i)));
        }
    
        int res=0;
        int cmax = 1<<31;
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int h=top.first;
            cmax = max(cmax, h);
            int x=top.second/m, y=top.second%m;
            
            for (int i=0; i<4; ++i) {
                int vi=x+d[i][0], vj=y+d[i][1];
                if (vi<0 || vi==n || vj<0 || vj==m || visit[vi][vj])    continue;
                visit[vi][vj]=true;
                pq.push(MK(heightMap[vi][vj], (vi*m+vj)));
                res += max(0, cmax-heightMap[vi][vj]);
            }
        }
        return res;
    }
};