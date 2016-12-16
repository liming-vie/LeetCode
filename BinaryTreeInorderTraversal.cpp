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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode*move=root;
        while(!st.empty() || move) {
            if(move) {
                st.push(move);
                move=move->left;
            } else {
                move=st.top();
                st.pop();
                res.push_back(move->val);
                move=move->right;
            }
        }
        return res;
    }
};