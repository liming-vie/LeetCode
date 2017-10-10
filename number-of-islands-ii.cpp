class Solution {
public: 
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<int>> islands;
    vector<vector<pair<int, int>>> parent;
    
    pair<int, int> find(const pair<int, int>& point) {
        if (parent[point.first][point.second]==point)   return point;
        
        parent[point.first][point.second] = find(parent[point.first][point.second]);
        
        return parent[point.first][point.second];
    }
    
    bool merge(const pair<int, int>& a, const pair<int, int>& b) {
        const auto& pa = find(a);
        const auto& pb = find(b);
        if (pa!=pb){
            parent[pa.first][pa.second] = pb;  
            return true;
        } 
        return false;
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        islands = vector<vector<int>>(m,vector<int>(n,0));
        parent = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n));
        vector<int> res;
        
        int count = 0;
        for (const auto& p : positions) {
            islands[p.first][p.second] = 1;
            parent[p.first][p.second] = p;
            ++count;
            for (int i=0; i<4; ++i) {
                int vi=p.first+d[i][0];
                int vj=p.second+d[i][1];
                if (vi<0 || vj<0 || vi==m || vj==n || !islands[vi][vj])
                    continue;
                count -= merge(p, make_pair(vi,vj));
            }
            res.push_back(count);
        }
        return res;
    }
};