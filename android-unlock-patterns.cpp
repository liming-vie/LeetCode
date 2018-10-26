class Solution {
public:
    bool select[9][9] = {{0}};
    
    bool isValid(int pi, int pj, int i, int j) {
        if (select[i][j])   return false;
        if (pi==i && abs(pj-j)==2) {
            int mj = min(pj, j)+1;
            return select[i][mj];
        }
        if (pj==j && abs(pi-i)==2) {
            int mi = min(pi, i)+1;
            return select[mi][j];
        }
        if (abs(i-pi)==2 && abs(j-pj)==2) {
            return select[1][1];
        }
        return true;
    }
    
    int dfs(int m, int n, int ci, int cj, int vi) {
        if (vi>n) return 0;
        if (n==vi)  return 1;
        
        int res=((vi>=m)?1:0);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (isValid(ci, cj, i, j)) {
                    select[i][j] = true;
                    res += dfs(m, n, i, j, vi+1);
                    select[i][j] = false;
                }
            }
        }
        return res;
    }
    
    int numberOfPatterns(int m, int n) {
        if (n==0)   return 0;
        
        int res=0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                select[i][j] = true;
                res += dfs(m, n, i,j,1);
                select[i][j] = false;
            }
        }
        return res;
    }
};
