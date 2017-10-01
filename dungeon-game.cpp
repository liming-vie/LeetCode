const int MAXH = ~(1<<31);
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        if(m==0) return 0;
        int n=dungeon[0].size();
        if (n==0) return 0;
        for(int i=m-1; i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                int d=MAXH, r=MAXH;
                if(i!=m-1) {
                    d=dungeon[i+1][j]-dungeon[i][j];
                }
                if (j!=n-1) {
                    r=dungeon[i][j+1]-dungeon[i][j];
                }
                
                if (d==MAXH && r==MAXH) {
                    if (dungeon[i][j] <0) {
                        dungeon[i][j] = -dungeon[i][j]+1;
                    }
                    else {
                        dungeon[i][j] = 1;
                    }
                } else {
                    dungeon[i][j] = MAX(1, MIN(d,r));
                }
            }
        }
        return dungeon[0][0];
    }
};