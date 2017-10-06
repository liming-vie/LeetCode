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
    int diameter = 0;
    
    int func(TreeNode* root) {
        if (!root)  return 0;
        
        int l=0, r=0;
        if (root->left) {
            l = func(root->left) + 1;
        }
        if (root->right) {
            r = func(root->right) + 1;
        }
        
        diameter = max(diameter, r+l);
        
        return max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        func(root);
        return diameter;
    }
};