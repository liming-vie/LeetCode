class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        if (!n) return 0;
        
        for (int i=1; i<n; ++i) {
            for (int c=0; c<3; ++c) {
                int min = -1;
                for (int t=0; t<3; ++t) {
                    if (t==c)   continue;
                    if (min<0 || min>costs[i-1][t])
                        min=costs[i-1][t];
                }
                costs[i][c]+=min;
            }
        }
        
        return min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]);
    }
};