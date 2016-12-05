class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=(m>0?matrix[0].size():0);
        bool row=false,colum=false;
        for(int i=0; i<m; ++i)
            if(!matrix[i][0]){
                colum=true;
                break;
            }
        for(int j=0; j<n; ++j)
            if(!matrix[0][j]){
                row=true;
                break;
            }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(!matrix[i][j]){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1; i<m; ++i)
            if(!matrix[i][0]){
                for(int j=1; j<n; ++j)
                    matrix[i][j]=0;
            }
        for(int j=1; j<n; ++j)
            if(!matrix[0][j])
                for(int i=1; i<m; ++i)
                    matrix[i][j]=0;
        if(row)
            for(int j=0; j<n; ++j)
                matrix[0][j]=0;
        if(colum)
            for(int i=0; i<m; ++i)
                matrix[i][0]=0;
    }
};