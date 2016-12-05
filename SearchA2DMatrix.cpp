#define BINARY(val)                  \
    while(l<r) {                     \
        mid=(l+r)>>1;                \
        if(val<target)   l=mid+1;    \
        else if(val>target)  r=mid-1;\
        else return true;            \
    }

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()-1, mid;
        BINARY(matrix[mid][0]);
        
        int row=l;
        if(matrix[l][0]>target) --row;
        if(row<0)   return false;
        
        l=0, r=matrix[0].size()-1;
        BINARY(matrix[row][mid]);
        
        return matrix[row][l]==target;
    }
};