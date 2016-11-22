class Solution {
public:
    void find(vector<int>&num, int vi, int target, vector<int>tmp, int cursum, set<vector<int> >&res){
        if(vi==num.size()||cursum>target)   return;
        
        int n=num.size();
        for(int i=vi; i<n;++i){
            cursum+=num[i];
            if(cursum>target)   return;
            
            tmp.push_back(num[i]);
            
            if(cursum==target){
                res.insert(tmp);
                return;
            }
            
            find(num,i+1,target,tmp,cursum,res);
            
            cursum-=num[i];
            tmp.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> >res;
        if(num.size()==0||target<0)   return res;
        
        sort(num.begin(),num.end());
 
        if(num[0]>target)   return res;
        
        vector<int> tmp;
        set<vector<int> > tres;
        find(num,0,target,tmp, 0,tres);
        for(set<vector<int> >::iterator i=tres.begin(); i!=tres.end(); ++i){
            res.push_back(*i);
        }
        return res;
    }
};