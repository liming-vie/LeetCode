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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n=intervals.size();
        for (auto i=intervals.begin(); i!=intervals.end(); ++i) {
            if (newInterval.start < i->start) {
                intervals.insert(i, newInterval);
                break;
            }
        }
        if (intervals.size() == n) {
            intervals.push_back(newInterval);
        }
        ++n;
        
        Interval cur(intervals[0]);
        int idx = 0;
        for (int i=1; i<n; ++i) {
            if (cur.end < intervals[i].start) {
                intervals[idx++] = cur;
                cur = intervals[i];
            }
            else if (cur.end < intervals[i].end) {
                cur.end = intervals[i].end;
            }
        }
        intervals[idx++] = cur;
        
        intervals.resize(idx);
        return intervals;
    }
};