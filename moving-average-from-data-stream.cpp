class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size), sum(0.) {
    }
    
    double next(int val) {
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return (double)sum / min(size, (int)q.size());
    }
    
private:
    double sum;
    queue<int> q;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
