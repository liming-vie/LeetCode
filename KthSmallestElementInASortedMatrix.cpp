#define mp(a,b) make_pair(a,b)

struct cmp {
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b) {
        return a.first>b.first;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> q;
        
        int n=matrix.size();
        for(int i=0; i<n; ++i) {
            q.push(mp(matrix[0][i], mp(0,i)));
        }
        
        while(--k) {
            int x=q.top().second.first+1;
            int y=q.top().second.second;
            q.pop();
            
            if(x!=n) {
                q.push(mp(matrix[x][y], mp(x,y)));
            }
        }
        
        return q.top().first;
    }
};