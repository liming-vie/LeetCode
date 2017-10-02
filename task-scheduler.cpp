class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count; // task, total count
        for (const auto&c : tasks) {
            ++count[c];
        }
        
        multimap<int, char, greater<int>> mp; // count, task
        for (auto &kv : count) {
            mp.insert(make_pair(kv.second, kv.first));
            kv.second = -1; // position
        }
        
        int res = 0;
        while (!mp.empty()) {
            auto iter = mp.begin();
            for(auto iter=mp.begin(); iter!=mp.end(); ++iter) {
                if (count[iter->second] == -1 || count[iter->second] + n < res) {
                    count[iter->second] = res;
                    if (iter->first > 1) {
                        mp.insert(make_pair(iter->first-1, iter->second));    
                    }
                    mp.erase(iter);
                    break;
                }
            }
            ++res;
        }
        
        return res;
    }
};