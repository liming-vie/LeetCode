class Solution {
private:
    struct Num{
        int val, idx;
    };
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n<4) return res;

        sort(nums.begin(), nums.end());
        map<int, vector<pair<Num, Num>>> mp;
        for (int i = 0; i<n; ++i)
            for (int j = i + 1; j<n; ++j) {
                mp[nums[i] + nums[j]].push_back(
                    make_pair(Num{ nums[i], i }, Num{ nums[j], j }));
            }

        auto l = mp.begin(), r = mp.end(); --r;
        bool equal = false;
        while (!equal && l->first <= r->first) {
            equal = (l==r);
            int s = l->first + r->first;
            if (s<target)    ++l;
            else if (s>target)   --r;
            else {
                auto& v1 = l->second;
                auto& v2 = r->second;
                int count = 0;
                for (int i = 0; i<l->second.size(); ++i) {
                    for (int j = 0; j<r->second.size(); ++j) {
                        if (v1[i].second.idx >= v2[j].first.idx) continue;
                        vector<int> cur{ v1[i].first.val, v1[i].second.val,
                            v2[j].first.val, v2[j].second.val };
                        // judge if duplicate, still O(n^2)?
                        bool valid = true;
                        for (int k = res.size() - 1; k>=(int)res.size() - count; --k)
                            if (res[k] == cur) {
                                valid = false;
                                break;
                            }

                        if (!valid)  continue;
                        res.push_back(cur);
                        ++count;
                    }
                }
                ++l;
                --r;
            }
        }

        return res;
    }
};