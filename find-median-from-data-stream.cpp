class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> larger;
    priority_queue<int> smaller;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smaller.empty() || smaller.top() >= num) {
            smaller.push(num);
        } else {
            larger.push(num);
        }
    
        if (smaller.size()>larger.size()+1) {
            larger.push(smaller.top());
            smaller.pop();
        } else if (larger.size() > smaller.size()) {
            smaller.push(larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        double res=smaller.top();
        if (larger.size()==smaller.size()) {
            res += larger.top();
            res /= 2;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */