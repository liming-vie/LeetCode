class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> count;
        for (char c:s)  ++count[c];
        
        multimap<int, pair<char, int>, greater<int>> mp;
        for (const auto& kv:count)
            mp.insert(make_pair(kv.second, make_pair(kv.first, -1)));
        
        string res;
        while (!mp.empty()) {
            auto iter=mp.begin();
            for (; iter!=mp.end(); ++iter) {
                if (iter->second.second < 0 || res.length()-iter->second.second>=k) {
                    break;
                }
            }
            if (iter==mp.end()) return "";
            
            mp.erase(iter);
            if (iter->first>1) {
                mp.insert(make_pair(iter->first-1, make_pair(iter->second.first, res.length())));
            }
            res += iter->second.first;
        }
        
        return res;
    }
};