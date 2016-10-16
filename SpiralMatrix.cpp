class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0;
        int n=matrix.size(), m=n>0?matrix[0].size():0;
        vector<int> res;
        int u=-1, d=n, l=-1, r=m;
        int flag=0;
        while(i>u && i<d && j>l && j<r) {
            switch(flag) {
            case 0:
                while(j<r) res.push_back(matrix[i][j++]);
                ++u;
                --j;
                ++i;
                break;
            case 1:
                while(i<d) res.push_back(matrix[i++][j]);
                --r;
                --i;
                --j;   
                break;
            case 2:
                while(j>l) res.push_back(matrix[i][j--]);
                --d;
                ++j;
                --i;
                break;
            case 3:
                while(i>u) res.push_back(matrix[i--][j]);
                ++l;
                ++i;    
                ++j;
            }
            flag = (flag+1)%4;
        }
        return res;
    }
};