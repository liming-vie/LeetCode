// similar to 3. Longest Substring Without Repeating Characters

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n=words.size();
        if(!n)  return res;
        
        int l1=s.length(), l2=words[0].length(), l=l2*n;
        if(l>l1)    return res;
        
        map<string, int> mp;
        for(auto i:words)   ++mp[i];
        
        map<string, int> count;
        
        for(int i=0; i<l2; ++i) {
            // use cur to record words inside window
            // use last to record left window point
            int cur=0, last=i;
            count.clear();
            for(int j=i; j<l1; j+=l2) {
                string str=s.substr(j,l2);
                if(mp.find(str) == mp.end()) {
                    last=j+l2;
                    cur=0;
                    count.clear();
                    continue;
                }
                if(mp[str]<(++count[str])) {
                    for(int k=last; k<j; k+=l2) {
                        string tmp=s.substr(k, l2);
                        --cur;
                        --count[tmp];
                        if(tmp==str) {
                            last=k+l2;
                            break;
                        }
                    }
                }
                if((++cur)==n)  res.push_back(last);
            }
        }
        return res;
    }
};