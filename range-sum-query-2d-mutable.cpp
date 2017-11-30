class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        n=matrix.size();    if (!n) return;
        m=matrix[0].size(); if (!m) return;
        
        nums = vector<vector<int>>(n,vector<int>(m, 0));
        tree = vector<vector<int>>(n+1,vector<int>(m+1, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - nums[row][col];
        nums[row][col]=val;
        for (int i=row+1; i<=n; i+=(i&(-i))) {
            for (int j=col+1; j<=m; j+=(j&(-j))) {
                tree[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) + sum(row1-1, col1-1) - sum(row2, col1-1) - sum(row1-1, col2);
    }
    
    int sum(int row, int col) {
        int res=0;
        for (int i=row+1; i>0; i-=(i&(-i))) {
            for (int j=col+1; j>0; j-=(j&(-j))) {
                res+=tree[i][j];
            }
        }
        return res;
    }
    
    int m, n;
    vector<vector<int>> tree, nums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */