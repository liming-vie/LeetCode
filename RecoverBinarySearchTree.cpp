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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *move=root, *pre=NULL, *first=NULL, *second=NULL;
        while(!st.empty() || move) {
            if(move) {
                st.push(move);
                move=move->left;
            } else {
                move=st.top();
                st.pop();
                if(pre && pre->val>move->val) {
                    if(!first)   first=pre;
                    second=move;
                }
                pre=move;
                move=move->right;
            }
        }
        if(first && second) 
            swap(first->val, second->val);
    }
};