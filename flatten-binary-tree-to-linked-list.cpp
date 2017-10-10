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
    void flatten(TreeNode* root) {
        if(!root)   return;
        
        stack<TreeNode*> st;
        TreeNode*move=root;
        TreeNode*pre=NULL;
        while(!st.empty() || move) {
            if (move) {
                while (move) {
                    st.push(move);
                    if (pre)    pre->right = move;
                    pre = move;
                    move = move->left;
                    pre->left = pre->right;
                }
            } else {
                move = st.top();
                st.pop();
                auto tmp = move;
                move = move->left;
                tmp->left = NULL;
            }
        }
    }
};