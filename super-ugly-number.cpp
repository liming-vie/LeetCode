class Solution {
public:
    struct Num {
        Num (int i, int v, int p) : idx(i), val(v), p(p) {}
        
        bool operator<(const Num& other) const {
            return this->val > other.val;
        }
        
        int idx, val, p;
    };
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n==1)   return 1;
        
        priority_queue<Num> pq;
        for (int p : primes) {
            pq.push(Num(0, p, p));
        }
        
        vector<int> vec(n, 1);
        int idx=1;
        
        while (idx<n) {
            int val = pq.top().val;
            vec[idx++] = val;
            while (pq.top().val == val) {
                const auto& top = pq.top();
                pq.push(Num(top.idx+1, vec[top.idx+1]*top.p, top.p));
                pq.pop();
            }
        }
        
        return vec.back();
    }
};