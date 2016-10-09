class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length() < k)  return 0;
        
        map<char,int> mp;
        for(int i=0; i<s.length(); ++i)
            ++mp[s[i]];
        map<char, bool> hash;
        for(auto kv : mp) 
            if (kv.second < k) hash[kv.first] = true;
        if(hash.size() == 0)    return s.length();
        
        int last = 0;
        int res=0;
        for(int i=0; i<=s.length(); ++i) {
            if(i==s.length() || hash[s[i]]){
                if(last < i) {
                    int tmp = longestSubstring(s.substr(last, i-last), k);
                    res = tmp > res ? tmp : res;
                }
                last = i+1;
            }
        }
        return res;
    }
};