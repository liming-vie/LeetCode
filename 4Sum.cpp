class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        vector<int> tmp;
        int n=num.size();
        for(int i=0; i<n; ++i){
            if(i>0 && num[i-1]==num[i]) continue;
            for(int j=i+1; j<n;++j){
                if(j>i+1 && num[j-1]==num[j])   continue;
                int t=target-num[i]-num[j];
                int l=j+1,r=n-1;
                while(l<r){
                    if(num[l]+num[r]<t){
                        l++;
                        while(l<r && num[l-1]==num[l])  ++l;
                    }else if(num[l]+num[r]>t){
                        --r;
                        while(l<r && num[r+1]==num[r])  --r;
                    }else{
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        res.push_back(tmp);
                        tmp.clear();
                        l++;
                        while(l<r && num[l-1]==num[l])  ++l;
                        --r;
                        while(l<r && num[r+1]==num[r])  --r;
                    }
                }
            }
        }
        return res;
    }
};