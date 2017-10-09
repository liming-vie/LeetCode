#define MP(a,b) make_pair(a, b)
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        points.reserve(buildings.size() << 1);
        for (const auto& build : buildings) {
            points.push_back(MP(build[0], (-build[2])));
            points.push_back(MP(build[1], build[2]));
        }
        sort(points.begin(), points.end());
        
        int prev=0;
        multiset<int, greater<int>> st;
        vector<pair<int, int>> res;
        for (const auto& point : points) {
            if (point.second < 0) {
                st.insert(-point.second);
            } else {
                st.erase(st.find(point.second));
            }
            
            if (*st.begin() != prev) {
                res.push_back(MP(point.first, *st.begin()));
                prev = *st.begin();
            }
        }
        return res;
    }
};