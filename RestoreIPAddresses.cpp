class Solution {
public:
  vector<string> res;

  void func(string s, string cur, int n, int vi) {
    if (n == 4 && vi != s.length() || (n != 4 && vi == s.length()) || vi>s.length())
      return;
    if (n == 4) {
      res.push_back(cur.substr(0,cur.length()-1));
      return;
    }
    if (s[vi] == '0') {
      func(s, cur + "0.", n + 1, vi + 1);
      return;
    }
    int u = vi + 3;
    if (u>s.length() || atoi(s.substr(vi, 3).c_str())>255) --u;
    for (int i = vi; i<u; ++i) {
      cur += s[i];
      func(s, cur + '.', n + 1, i + 1);
    }
  }

  vector<string> restoreIpAddresses(string s) {
    func(s, "", 0, 0);

    return res;
  }
};