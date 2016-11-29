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
        if(n==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<Interval> res;
        Interval tmp;
        if(intervals[0].start < newInterval.start){
            tmp=intervals[0];
        }else{
            tmp=newInterval;
            newInterval=Interval();
        }
        
        for(int i=0; i<n;++i){
            if(newInterval.start!=0 && newInterval.end!=0 && newInterval.start<intervals[i].start){
                if(tmp.end<newInterval.start){
                    res.push_back(tmp);
                    tmp=newInterval;
                }
                else if(tmp.end<newInterval.end){
                    tmp.end=newInterval.end;
                }
                newInterval=Interval();
            }
            if(tmp.end<intervals[i].start){
                res.push_back(tmp);
                tmp=intervals[i];
            }
            else if(tmp.end<intervals[i].end)
                tmp.end=intervals[i].end;
        }
        if(newInterval.start!=0&&newInterval.end!=0){
            if(tmp.end<newInterval.start){
                    res.push_back(tmp);
                    tmp=newInterval;
                }
                else if(tmp.end<newInterval.end){
                    tmp.end=newInterval.end;
                }
        }
        res.push_back(tmp);
        return res;
    }
};