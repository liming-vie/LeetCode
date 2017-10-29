class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2)    return 0;
        
        vector<int> first(n+1);
        first[0]=first[1]=0;
        int cmin=prices[0];
        for (int i=1; i<n; ++i) {
            if (cmin < prices[i]) {
                first[i+1] = max(first[i], prices[i]-cmin);
            } else {
                cmin = prices[i];
                first[i+1] = first[i];
            }
        }
        
        vector<int> second(n+2);
        second[n] = second[n+1] = 0;
        int cmax=prices[n-1];
        for (int i=n-2; i>=0; --i) {
            if (cmax > prices[i]) {
                second[i+1] = max(second[i+2], cmax-prices[i]);
            } else {
                cmax = prices[i];
                second[i+1]=second[i+2];
            }
        }
        
        int res=0;
        for (int i=1; i<=n+1; ++i) {
            res = max(res, first[i-1]+second[i]);
        }
        return res;
    }
};