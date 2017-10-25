class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res(numCourses);
        vector<int> degree(numCourses, 0);
        vector<vector<int>> next(numCourses);
        
        for (const auto kv : prerequisites) {
            ++degree[kv.first];
            next[kv.second].push_back(kv.first);
        }
        
        int tail=0;
        for (int i=0; i<numCourses; ++i) {
            if (!degree[i]) {
                res[tail++]=i;
            }
        }
        
        int start = 0;
        while (start < tail) {
            for (int n : next[res[start]]) {
                if (--degree[n]==0)
                    res[tail++] = n;
            }
            ++start;
        }
        
        if (tail!=numCourses) return vector<int>();
        return res;
    }
};