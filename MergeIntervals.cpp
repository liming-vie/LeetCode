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
    static bool comp(const Interval&a, const Interval&b){
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int n=intervals.size();
        if(n==0) return res;
        
        sort(intervals.begin(),intervals.end(),comp);
        Interval tmp=intervals[0];
        for(int i=1; i<n; ++i){
            if(intervals[i].end<=tmp.end)   continue;
            if(intervals[i].start>tmp.end){
                res.push_back(tmp);
                tmp=intervals[i];
                continue;
            }
            tmp.end=intervals[i].end;
        }
        res.push_back(tmp);
        return res;
    }
};