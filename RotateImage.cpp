class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int tmp;
        int r=0;
        for(int i=0; i<=n/2; ++i){
            for(int j=i; j<n-i-1; ++j){
                tmp=matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-i-1][n-1-j];
                matrix[n-i-1][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;       
            }
        }
    }
};