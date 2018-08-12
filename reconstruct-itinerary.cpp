class Solution {
public:
    map<string, multiset<string>> edges;
    vector<string> res;
    
    bool dfs(int n) {
        if (res.size() == n) {
            return true;
        }
        if (edges.find(res.back()) == edges.end())
            return false;
        auto& st = edges[res.back()];
        for (auto iter=st.begin(); iter!=st.end(); ++iter) {
            string str = *iter;
            res.push_back(str);
            st.erase(st.find(str));
            if (dfs(n))
                return true;
            res.pop_back();
            iter=st.insert(str);
        }
        return false;
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        res.clear();
        if (tickets.size() == 0)    return res;
        
        edges.clear();
        for (const auto& p:tickets) {
            edges[p.first].insert(p.second);
        }
        res.push_back("JFK");
        dfs(tickets.size()+1);
        return res;
    }
};
