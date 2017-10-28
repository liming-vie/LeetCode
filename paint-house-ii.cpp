class Solution {
public:
    int findMin(const vector<int>& row) {
        int min1=row[0];
        for (int i=1; i<row.size(); ++i)    min1=min(row[i], min1);
        return min1;
    }
    
    void setMin(vector<int>& row) {
        int min1=findMin(row);
        int min2=-1, count=0;
        for (int n : row) {
            if (n==min1) {
                ++count;
                continue;
            }
            if (min2==-1 || min2>n) min2=n;
        }
        if (min2==-1 || count>1)   min2=min1;
        
        for (int i=0; i<row.size(); ++i) {
            row[i] = (row[i]==min1) ? min2 : min1;
        }
    }
    
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size(); if(!n)  return 0;
        int k=costs[0].size();
        
        setMin(costs[0]);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<k; ++j) {
                costs[i][j] += costs[i-1][j];
            }
            setMin(costs[i]);
        }
        
        return findMin(costs[n-1]);
    }
};