class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int i=0, j=0;
        int u=0,d=n-1,l=0,r=n-1;
        int idx=1,flag=0;
        while(u<=d && l<=r) {
            switch(flag) {
            case 0:
                while(j<=r)  res[i][j++] = idx++;
                ++u;
                --j;
                ++i;
                break;
            case 1:
                while(i<=d) res[i++][j] = idx++;
                --r;
                --i;
                --j;
                break;
            case 2:
                while(j>=l) res[i][j--] = idx++;
                --d;
                ++j;
                --i;
                break;
            case 3:
                while(i>=u) res[i--][j] = idx++;
                ++l;
                ++i;
                ++j;
            }
            flag = (flag+1) & 3; // (flag+1)%4
        }
        return res;
    }
};