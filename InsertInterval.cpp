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
        bool flag=true;
        for(auto i=intervals.begin(); i!=intervals.end(); ++i) {
            if(newInterval.start<=i->start) {
                intervals.insert(i, newInterval);
                flag=false;
                break;
            }
        }
        if(flag) {
            intervals.push_back(newInterval);
        }
        
        vector<Interval> res;
        Interval tmp=intervals[0];
        for(int i=1; i<intervals.size(); ++i) {
            if(intervals[i].end <= tmp.end) continue;
            if(intervals[i].start <= tmp.end) {
                tmp.end=intervals[i].end;
            }
            else {
                res.push_back(tmp);
                tmp=intervals[i];
            }
        }
        res.push_back(tmp);
        return res;
    }
};