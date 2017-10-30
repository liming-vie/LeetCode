class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (k>=(n>>1)) {
            return maxProfit2(prices);
        }
        vector<int> local(k+1, 0);
        vector<int> global(k+1, 0);
        
        for (int i=1; i<n; ++i) {
            int diff=prices[i]-prices[i-1];
            for (int j=k; j>=1; --j) {
                local[j] = max(local[j]+diff, global[j-1]+diff);
                global[j] = max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
    
    int maxProfit2(const vector<int>& prices) {
        int res=0;
        for (int i=1; i<prices.size(); ++i)
            res += max(0, prices[i]-prices[i-1]);
        return res;
    }
};