class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if (n<2)    return 0;
        
        vector<int> buy(n); buy[0]=-prices[0]; buy[1]=max(buy[0], -prices[1]);
        vector<int> sell(n); sell[0]=0; sell[1]=max(0, prices[1]-prices[0]-fee);
        
        for (int i=2; i<n; ++i) {
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]-fee);
        }
        return sell[n-1];
    }
};