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
    TreeNode *first, *second, *pre;

    void Inorder(TreeNode* root) {
        if(!root)   return;
        Inorder(root->left);
        if(pre && pre->val > root->val) {
            if(!first) first=pre;
            second=root;
        }
        pre=root;
        Inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        Inorder(root);
        if(first && second) 
            swap(first->val, second->val);
    }
};