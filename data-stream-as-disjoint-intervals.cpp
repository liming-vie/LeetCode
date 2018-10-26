/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int val) {
        auto cur = Interval(val, val);
        auto lower = st.lower_bound(cur);
        if (lower != st.end()) {
            if (lower->start == val)    return;
            
            if (lower->start == val+1) {
                cur.end = lower->end;
                lower=st.erase(lower);
            }
        }
        
        if (!st.empty() && lower!=st.begin()) {
            --lower;
            if (lower->end >= val)    return;
            if (lower->end == val-1) {
                cur.start = lower->start;
                st.erase(lower);
            }
        }
        
        st.insert(cur);
    }
    
    vector<Interval> getIntervals() {
        res.clear(); 
        for (const auto &it : st) {
            res.push_back(it);
        }
        return res;
    }
    
    struct comp {
        bool operator() (const Interval& a, const Interval& b) const {
            if (a.start == b.start) return a.end <= b.end;
            return a.start <= b.start;
        }
    };
    
    vector<Interval> res;
    set<Interval, comp> st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */