class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(!numRows)    return res;
        
        vector<int> cur;
        res.push_back(vector<int>(1,1));
        for (int i=1; i<numRows; ++i) {
            cur.push_back(1);
            for(int j=1; j<i; ++j) {
                cur.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            cur.push_back(1);
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }
};