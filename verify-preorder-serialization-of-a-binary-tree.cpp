class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<bool> left;
        int i=0;
        while (i<preorder.length()) {
            if (preorder[i] == '#') {
                i+=2;
                while (!left.empty() && !left.top()) {
                    left.pop();
                }
                if (left.empty())   break;
                left.pop();
                left.push(false);
            } else {
                left.push(true);
                int vi = preorder.find(',', i);
                i = (vi==-1?preorder.length():vi) + 1;
            }
        }
        return i>=preorder.length() && left.empty();
    }
};
