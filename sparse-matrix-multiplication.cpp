#define MK(a,b) make_pair(a,b)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size() == 0 || B.size() == 0) return vector<vector<int>>();
        
        vector<unordered_map<int, int>> rows;
        for (const auto&row : A) {
            unordered_map<int, int> info;
            for (int i=0; i<row.size(); ++i) {
                if (row[i]) {
                    info[i] = row[i];
                }
            }
            rows.push_back(info);
        }
        
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        for (int i=0; i<A.size(); ++i) {
            for (int j=0; j<B[0].size(); ++j) {
                for (const auto&iter : rows[i]) {
                    res[i][j] += iter.second * B[iter.first][j];
                }
            }
        }
        
        return res;
    }
};