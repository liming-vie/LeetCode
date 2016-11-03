class Solution {
public:
int longestValidParentheses(string s) {
  int n = s.size();
  if (n <= 1) return 0;
  
  int bp[50000]={0};
  bp[1]=(s[0]=='('&&s[1]==')')?2:0;
  int res=bp[1];
  for(int i=2; i<n; ++i){
      if(s[i]=='('){
          bp[i]=0;
          continue;
      }
      if(s[i-1]=='(')  bp[i]=bp[i-2]+2;
      else if(i>bp[i-1] && s[i-bp[i-1]-1]=='(')   bp[i]=bp[i-1]+2;
      if(i>=bp[i])    bp[i]+=bp[i-bp[i]];
      if(res<bp[i])   res=bp[i];
  }
  return res;
}
};