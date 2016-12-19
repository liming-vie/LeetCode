class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int min=prices[0], res=0;
        for(int i=1; i<n; ++i) {
            min=min<prices[i]?min:prices[i];
            int tmp=prices[i]-min;
            res=tmp>res?tmp:res;
        }
        return res;
    }
};