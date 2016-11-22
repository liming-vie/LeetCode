class Solution {
public:
string countAndSay(int n) {
  if (n == 0)    return "";
  if (n == 1)    return "1";
  string s = "1",tmp;
  int len;
  for (int i = 1; i<n; ++i){
    len = s.length();
    int j = 0;
    int t;
    tmp = "";
    while (j<len){
      ++j;
      t = 1;
      while (j<len && s[j] == s[j - 1])    ++t, ++j;
      tmp += ('0' + t);
      tmp += s[j - 1];
    }
    s = tmp;
  }
  return s;
}
};