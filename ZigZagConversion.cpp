class Solution {
public:
    string convert(string s, int nRows) {
    int n = s.length();
  if (n <= nRows || nRows <= 1) return s;

  int col = 0;
  while (n>0){
    n -= nRows;
    col++;
    if (n >= (nRows - 2)){
      n -= nRows - 2;
      col += (nRows - 2);
    }
    else if (n>0){
      col += n;
      n = 0;
    }
  }
  n = s.length();
  string res;
  int maxd = (nRows << 1) - 2;
  int sum = 0;
  for (int i = 0; i<nRows; ++i){
    int p = i;
    int d = maxd - (i << 1);
    for (int j = 0; j<col; ++j){
      res.push_back(s[p]);
      if (d == 0)    d = maxd;
      p += d;
      if (p >= n)    break;
      d = maxd - d;
    }
  }
  return res;   
    }
};