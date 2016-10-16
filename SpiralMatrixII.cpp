class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        for(int j=0; j<n; ++j)
            tmp.push_back(0);
        for(int i=0; i<n; ++i)
            res.push_back(tmp);
        int i=0,j=0;
        int l=0,r=n-1,u=0,d=r;
        int curn=1;
        while(l<=r || u<=d){
            while(l<=r && j<r){
                res[i][j]=curn++;
                ++j;
            }
            ++u;
            while(u<=d && i<d){
                res[i][j]=curn++;
                ++i;
            }
            --r;
            while(l<=r && j>l){
                res[i][j]=curn++;
                --j;
            }
            --d;
            while(u<=d && i>u){
                res[i][j]=curn++;
                --i;
            }
            ++l;
        }
        if(i>=0 && j>=0 && i<n && j<n)
            res[i][j]=curn++;
        return res;
    }
};