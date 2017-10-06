class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2)    return 0;
        int min = prices[0], res=0;
        for (int i=1; i<n; ++i) {
            int tmp = prices[i] - min;
            res = tmp < res ? res : tmp;
            min = min < prices[i] ? min : prices[i];
        }
        return res;
    }
};