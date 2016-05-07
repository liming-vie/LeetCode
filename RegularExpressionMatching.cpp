class Solution {
public:
bool func(const char*s, const char*p, int n1, int n2){
  if (n1 == n2 && n1 == 0)  return true;
  if (n1 < 0 || n2 < 0 || (n2==0 && n1!=0)) return false;
  
  if (n2>1 && *(p + 1) == '*'){
    if (*p == '.' || (n1>0 && *p == *s))
      return func(s + 1, p, n1 - 1, n2) || func(s, p + 2, n1, n2 - 2);
    return func(s, p + 2, n1, n2 - 2);
  }
  else{
    if ((n1 > 0 && *p == *s) || *p == '.')
      return func(s + 1, p + 1, n1 - 1, n2 - 1);
    return false;
  }
}

    bool isMatch(const char *s, const char *p) {
        int len1=strlen(s);
        int len2=strlen(p);
        return func(s,p,len1,len2);
    }
};