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
        vn = &nestedList;
    }

    int next() {
        return (*vn)[vi++].getInteger();
    }

    bool hasNext() {
        while(true) {
            while (vn->size() == vi) {
                if(st.empty()) {
                    return false;
                }
                vi = idx.top(); idx.pop();
                vn = st.top(); st.pop();
            }
            while (vi < vn->size() && !(*vn)[vi].isInteger()) {
                st.push(vn);
                vn = &((*vn)[vi].getList());
                idx.push(vi+1);
                vi = 0;
            }
            if (vi < vn->size())   return true;
        }
    }
private:
    stack<int> idx;
    stack<vector<NestedInteger>*> st;
    int vi = 0;
    vector<NestedInteger>* vn;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */