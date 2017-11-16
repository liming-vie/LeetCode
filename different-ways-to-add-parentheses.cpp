class Solution {
public:
    vector<int> compute(const string& str, int start, int end) {
        int vi=start, cur=0;
        while(str[vi]>='0' && str[vi]<='9') {
            cur *= 10;
            cur += str[vi]-'0';
            ++vi;
        }
        if (vi > end)   return vector<int>{cur};
        
        vector<int> res;
        for (; vi<=end; ++vi) {
            if (str[vi]<'0' || str[vi]>'9') {
                const auto &left = compute(str, start, vi-1);
                const auto &right = compute(str, vi+1, end);
                for (int l:left) {
                    for (int r:right) {
                        int tmp;
                        switch (str[vi]) {
                            case '+':
                                tmp=l+r;
                                break;
                            case '-':
                                tmp=l-r;
                                break;
                            case '*':
                                tmp=l*r;
                                break;
                        }
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
    
    vector<int> diffWaysToCompute(string input) {
        if (input.length()==0)  return vector<int>();
        return compute(input, 0, input.length()-1);
    }
};