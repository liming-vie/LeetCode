class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> res;
  int m = matrix.size();
  int n = 0;
  if (m>0) n = matrix[0].size();
  int i = 0, j = 0;
  int u = 0, r = n - 1, d = m - 1, l = 0;
  while (u <= d || l <= r){
    while (j<r && u<=d){
      res.push_back(matrix[i][j]);
      ++j;
    }
    ++u;
    while (i<d && l<=r){
      res.push_back(matrix[i][j]);
      ++i;
    }
    --r;
    while (j>l && u<=d){
      res.push_back(matrix[i][j]);
      --j;
    }
    --d;
    while (i>u && l<=r){
      res.push_back(matrix[i][j]);
      --i;
    }
    ++l;
  }
  if(i>=0 && i<m && j>=0 && j<n)
      res.push_back(matrix[i][j]);
  return res;
}
};