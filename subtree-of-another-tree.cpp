/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string encode(TreeNode *root) {
        if (!root)  return "";
        
        stack<TreeNode*> st;

        st.push(root);
        stringstream ss;
        while (!st.empty()) {
            TreeNode* move = st.top();
            st.pop();
            if (move) {
                ss << "," << move->val;
                st.push(move->right);
                st.push(move->left);
            } else {
                ss << ",#";
            }
        }
        
        return ss.str();
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return encode(s).find(encode(t)) != -1;
    }
};