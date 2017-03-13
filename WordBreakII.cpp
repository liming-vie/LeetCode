class Solution {
public:
	vector<vector<char>> dp; // str.substr(i,j-i+1)
	vector<string> res;
	int len;
	string str;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto tmp:wordDict) st.insert(tmp);

        len=s.length();
        dp=vector<vector<char>>(len, vector<char>(len, 0));
        
  		for(int i=0; i<len; ++i) {
  			for(int j=i; j>=0; --j) {
  				if (st.find(s.substr(j,i-j+1))!=st.end()) {
  					dp[j][i]=1;
  					continue;
  				}
  				for(int k=j; k<i; ++k) {
  					if(dp[j][k] && dp[k+1][i]) {
  						dp[j][i]=2;
  						break;
  					}
  				}
  			}
  		}

  		if(dp[0][len-1]==0)	return res;

  		str=s;
  		search("", 0);

  		return res;
    }

    void search(string cur, int vi) {
    	if(vi==len)	{
    		res.push_back(cur);
    		return;
    	}

    	for(int i=vi; i<len; ++i) {
    		if(dp[vi][i]==1) {
    			string tmp=cur;
    			if(tmp.length()!=0)	tmp+=" ";
    			tmp += str.substr(vi, i-vi+1);
    			search(tmp, i+1);
    		}
    	}
    }
};