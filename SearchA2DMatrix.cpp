class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int u=0, d=matrix.size()-1;
        int l=0, r=(d<0?-1:matrix[0].size()-1);
        if(d<0||r<0)    return false;
        
        int mid;
        while(u<d){
            mid=(u+d)>>1;
            if(matrix[mid][0]==target)    return true;
            if(matrix[mid][0] < target)   u=mid+1;
            else    d=mid-1;
        }
        
        int vi=u;
        if(matrix[u][0]>target)    vi=u-1;
        
        if(vi<0)    return false;
        
        while(l<r){
            mid=(l+r)>>1;
            if(matrix[vi][mid]==target) return true;
            if(matrix[vi][mid]<target)    l=mid+1;
            else    r=mid-1;
        }
        
        if(matrix[vi][l]==target)   return true;
        return false;
    }
};