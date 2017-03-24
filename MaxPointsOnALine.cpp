/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#define MAX(a,b)	((a)>(b)?(a):(b))
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n=points.size();
        // use long double for high precision
        unordered_map<long double, int> count;
        int res=0;
        for(int i=0; i<n; ++i) {
        	int inf=0;
        	int same=1;	// include the point itself
        	count.clear();
        	for(int j=i+1; j<n; ++j) {
        		if(points[i].x==points[j].x) {
        			if(points[i].y==points[j].y)
        				++same;
        			else	++inf;
        		}
        		else {
        			long double k=((long double)points[i].y-points[j].y)/((long double)points[i].x-points[j].x);
        			++count[k];
        		}
        	}
        	int tmp=inf;
        	for(auto pair : count) 
        		tmp = MAX(pair.second, tmp);
        	tmp+=same;
        	res = MAX(res, tmp);
        }
        return res;
    }
};