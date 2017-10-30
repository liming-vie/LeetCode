class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(); if (!n)    return;
        int m=matrix[0].size(); if (!m) return;
        
        bool firstRow = false;
        for (int i=0; i<m; ++i) {
            if (matrix[0][i]==0) {
                firstRow=true;
                break;
            }
        }
            
        bool firstCol = false;
        for (int i=0; i<n; ++i) {
            if (matrix[i][0]==0) {
                firstCol=true;
                break;
            }
        }
        
        for (int i=1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                if (matrix[i][j]==0) {
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        
        for (int i=1; i<n; ++i) {
            if (matrix[i][0]==0) 
                for (int j=1; j<m; ++j)
                    matrix[i][j]=0;
        }
        
        for (int i=1; i<m; ++i) {
            if (matrix[0][i]==0) 
                for (int j=1; j<n; ++j)
                    matrix[j][i]=0;
        }
        
        if (firstCol)
            for (int i=0; i<n; ++i)
                matrix[i][0]=0;
        
        if (firstRow)
            for (int i=0; i<m; ++i)
                matrix[0][i]=0;
    }
};