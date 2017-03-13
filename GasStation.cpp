class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int n=gas.size();
        int sum=0;
        int cur=0;
        int res=0;
        for(int i=0; i<n; ++i) {
        	int tmp=gas[i]-cost[i];
        	cur+=tmp;
        	sum+=tmp;
        	if(cur<0) {
        		res=i+1;
        		cur=0;
        	}
        }
        if(sum<0)	return -1;
        return res%n;
    }
};