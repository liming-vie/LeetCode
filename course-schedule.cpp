class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> next(numCourses);
        
        for (const auto& pair : prerequisites) {
            ++indegree[pair.first];
            next[pair.second].push_back(pair.first);
        }
        
        queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            if (!indegree[i])   q.push(i);
        }
        
        while (!q.empty()) {
            for (int n : next[q.front()]) {
                if (--indegree[n]==0) {
                    q.push(n);
                }
            }
            q.pop();
        }
        
        for (int i=0; i<numCourses; ++i)
            if (indegree[i]>0)
                return false;
        
        return true;
    }
};