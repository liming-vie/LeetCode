class ZigzagIterator {
public:
    vector<vector<int>::iterator> iters;
    vector<vector<int>::iterator> ends;
    int cur=0;
    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iters.push_back(v1.begin());
        iters.push_back(v2.begin());
        ends.push_back(v1.end());
        ends.push_back(v2.end());
    }

    int next() {
        if (iters[cur]==ends[cur]) cur = 1-cur;
        int res = *(iters[cur]++);
        cur = 1-cur;
        return res;
    }

    bool hasNext() {
        return iters[0]!=ends[0] || iters[1]!=ends[1];
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */