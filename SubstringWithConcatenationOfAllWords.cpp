class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        int n=L.size();
        if(n==0)    return res;
        
        int len1=S.size(),len2=L[0].size();
        if(len2==0){
            res.push_back(0);
            return res;
        }
        if(len1<len2)   return res;
        
        map<string,int> count,tmp;
        for(int i=0; i<n; ++i)  count[L[i]]++;
        
        int l=0, r=n*len2;
        while(r<=len1){
            tmp.clear();
            for(int i=l; i<r; i+=len2){
                string str=S.substr(i,len2);
                if(count.find(str)!=count.end()){
                    ++tmp[str];
                    
                    if(count[str]<tmp[str]) break;
                }else   break;    
            }
            if(tmp==count)  res.push_back(l);
            ++l,++r;
        }
        return res;
    }
};