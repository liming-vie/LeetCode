#include<map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)   return 0;
        map<char,int> c;
        map<char,int>::iterator mp;
        int res=1;
        int l=0;
        c.insert(make_pair(s[0],0));
        for(int i=1; i<s.length(); ++i){
            if((mp=c.find(s[i]))==c.end()){
                c.insert(make_pair(s[i],i));
            }else{
                if(mp->second >= l){
                   if(i-l > res) res = i-l;
                   l=(mp->second) + 1;
                }
                mp->second = i;
            }
        }
        if(s.length()-l > res) res = s.length()-l;
        return res;
    }
};