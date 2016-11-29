class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int>tmpres;
    bool is[50];
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        func(nums,0);
        return res;
    }
    
    void func(vector<int> &nums, int vi){
        if(vi==n){
            vector<int> tmp=vector<int>(tmpres);
            res.push_back(tmp);
            return ;
        }
        
        for(int i=0; i<n; ++i){
            if(is[i])
                continue;
            tmpres.push_back(nums[i]);
            is[i]=true;
            func(nums,vi+1);
            tmpres.pop_back();
            is[i]=false;
            int j;
            for(j=i+1; j<n; ++j)
                if(nums[i]!=nums[j])
                    break;
            i=j-1;
        }
    }
};