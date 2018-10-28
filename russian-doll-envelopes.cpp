class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), 
             [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.first < b.first || (a.first == b.first && a.second > b.second);
             });
    
        vector<int> dp;
        for (const auto &p:envelopes) {
            auto l = lower_bound(dp.begin(), dp.end(), p.second);
            if (l==dp.end()) {
                dp.push_back(p.second);
            } else {
                *l = p.second;
            }
        }
        return dp.size();
    }
};