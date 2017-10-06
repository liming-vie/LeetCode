/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        if (a.start == b.start) {
            return a.end < b.end;
        }
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2)   return intervals;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> res;
        Interval cur(intervals[0]);
        for (const auto& inter : intervals) {
            if (cur.end < inter.start) {
                res.push_back(cur);
                cur = inter;
            } else if (cur.end < inter.end) {
                cur.end = inter.end;
            }
        }
        res.push_back(cur);
        
        return res;
    }
};