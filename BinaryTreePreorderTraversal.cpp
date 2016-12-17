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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *move=root;
        while(!st.empty() || move) {
            if (move) {
                res.push_back(move->val);
                st.push(move);
                move=move->left;
            } else {
                move=st.top();
                st.pop();
                move=move->right;
            }
        }
        return res;
    }
};