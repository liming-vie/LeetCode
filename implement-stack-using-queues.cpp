class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int last;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        last=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int count=q.size();
        while ((count--) > 1) {
            q.push(q.front());
            last=q.front();
            q.pop();
        }
        int res=q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return last;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */