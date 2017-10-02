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
    static bool cmp(const Interval &a, const Interval &b) {
        if (a.start == b.start) {
            return a.end < b.end;
        }
        return a.start < b.start;
    }
    
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> ends;
        for(const auto& iter : intervals) {
            bool found = false;
            for (int i=0; i<ends.size(); ++i) {
                if (ends[i] <= iter.start) {
                    ends[i] = iter.end;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ends.push_back(iter.end);
            }
        }
        return ends.size();
    }
};