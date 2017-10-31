/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n=points.size();
        unordered_map<long double, int> count;
        int res=0;
        for (int i=0; i<n; ++i) {
            int inf=0, same=1;
            count.clear();
            for (int j=i+1; j<n; ++j) {
                if (points[i].x==points[j].x) {
                    if (points[i].y==points[j].y) ++same;
                    else ++inf;
                } else {
                    ++count[((long double)points[i].y-points[j].y)/((long double)points[i].x-points[j].x)];
                }
            }
            int tmp=inf;
            for (const auto& kv : count) {
                tmp=max(tmp, kv.second);
            }
            tmp += same;
            res = max(tmp, res);
        }
        return res;
    }
};