class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
             [](const vector<int>&a, const vector<int>&b) {return a.back()<b.back();});
        
        priority_queue<int> pq;
        int total = 0;
        for (const auto &kv : courses) {
            total += kv.front();
            pq.push(kv.front());
            if (total > kv.back()) {
                total -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};