class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    char cd[4] = {'d','u','r','l'};
    unordered_set<string> st;
    
    string search(vector<vector<int>>& grid, int vi, int vj) {
        if (vi < 0 || vi==grid.size() || vj<0 || vj==grid[0].size() || !grid[vi][vj]) return "";
        grid[vi][vj] = 0;
        
        string str;
        for (int i=0; i<4; ++i) {
            str += cd[i] + search(grid, vi+d[i][0], vj+d[i][1]);
        }
        return str;
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        for (int i=0; i<grid.size(); ++i) 
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j]) {
                    const string& str = search(grid, i, j);
                    cout << str << endl;
                    if (st.find(str) == st.end())
                        st.insert(str);
                }
            }
        return st.size();
    }
};