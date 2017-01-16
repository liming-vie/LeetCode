#define MIN(a,b) (a)<(b)?(a):(b)
class Solution {
public:
    int minCut(string s) {
        int len=s.length();
        if(len<2) return 0;

        vector<vector<bool>> match(len, vector<bool>(len, false));
        vector<int> cut(len+1);
        for(int i=0; i<=len; ++i) cut[i]=i-1;

        for(int i=0; i<len; ++i)
          for(int j=i; j>=0; --j) {
            if(s[i]==s[j] && (i-j<2 || match[j+1][i-1])) {
              match[j][i]=true;
              cut[i+1]=MIN(cut[i+1], cut[j]+1);
            }
          }

        return cut[len];
    }
};