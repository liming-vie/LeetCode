class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1, st2;
    
    MyQueue() {
        
    }
    
    void helper() {
        if (!st1.empty())   return;
        
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st2.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = peek();
        st1.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        helper();
        return st1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */