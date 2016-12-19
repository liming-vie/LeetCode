#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        
        vector<int> dp1(n+1,0), dp2(n+1,0);
        int max=prices[n-1];
        for(int i=n-1; i>=1; --i) {
            max=MAX(max, prices[i-1]);
            int tmp=max-prices[i-1];
            dp1[i]=MAX(tmp, dp1[i+1]);
        }
        int min=prices[0];
        for(int i=2; i<=n; ++i) {
            min=MIN(min, prices[i-1]);
            int tmp=prices[i-1]-min;
            dp2[i]=MAX(tmp, dp2[i-1]);
        }
        int res=0;
        for(int i=1; i<=n; ++i) {
            res=MAX(res, dp1[i]+dp2[i-1]);
        }
        return res;
    }
};