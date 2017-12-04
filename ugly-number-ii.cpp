class Solution {
public:
    struct Num {
        Num(int a) : val(a), val2(a<<1), val3(a*3), val5(a*5) {}
        int val, val2, val3, val5;
    };
    
    int nthUglyNumber(int n) {
        vector<Num> vec;
        vec.reserve(n);
        vec.push_back(Num(1));
        int idx=1, i2=0, i3=0, i5=0;
        while (vec.size()<n) {
            int v = min(min(vec[i2].val2, vec[i3].val3), vec[i5].val5);
            if (v==vec[i2].val2) ++i2;
            if (v==vec[i3].val3) ++i3;
            if (v==vec[i5].val5) ++i5;
            vec.push_back(Num(v));
        }
        return vec.back().val;
    }
};