class Solution {
public:
#define FUNC(ui, uj, val)           \
    for (int i=0; i<ui; ++i) {      \
        for (int j=0; j<uj; ++j) {  \
            if (val) {              \
                idx.push_back(i);   \
            }                       \
        }                           \
    }                               \
    l=0, r=idx.size()-1;            \
    while (l<r) {                   \
        total+=(idx[r--]-idx[l++]); \
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.size()==0) return 0;
        
        int total=0, l, r;
        vector<int> idx;
        FUNC(grid.size(), grid[0].size(), grid[i][j]);
        idx.clear();
        FUNC(grid[0].size(), grid.size(), grid[j][i])
        return total;
    }
};