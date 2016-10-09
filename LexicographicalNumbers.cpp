class Solution {
public:
    void func(int li, int len, int prefix) {
        if(prefix>N)    return;
        res.push_back(prefix);
        if(li==len) {
            return;
        }
        prefix*=10;
        for(int i=0; i<10; ++i) {
            func(li+1, len, prefix+i);
        }
    }

    vector<int> lexicalOrder(int n) {
        res.clear();
        res.reserve(n);
        N=n;
        int count = 1;
        int tmp = n;
        while(tmp /= 10) 
            ++count;
        for(int i=1; i<10 && i<=n; ++i) {
            func(1, count, i);
        }
        return res;
    }
private:
    int N;
    vector<int> res;
};