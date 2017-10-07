/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        move = &nestedList;
        vi = 0;
    }

    int next() {
        return (*move)[vi++].getInteger();
    }

    bool hasNext() {
        while (true) {
            while (vi == move->size()) {
                if (st.empty()) {
                    return false;
                }
                auto top = st.top();
                move = top.first;
                vi = top.second;
                st.pop();
            }
            while (vi < move->size() && !(*move)[vi].isInteger()) {
                st.push(make_pair(move, vi+1));
                move = &((*move)[vi].getList());
                vi = 0;
            }
            if (vi < move->size()) {
                return true;
            }
        }
    }
    
private:
    stack<pair<vector<NestedInteger>*, int>> st;
    vector<NestedInteger> *move;
    int vi;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */