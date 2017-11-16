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
    int kthSmallest(TreeNode* root, int k) {
        int c=count(root->left);
        if (k<=c) return kthSmallest(root->left, k);
        if (k==c+1) return root->val;
        return kthSmallest(root->right, k-c-1);
    }
    
    int count(TreeNode* root) {
        if (!root)  return 0;
        return count(root->left) + count(root->right) + 1;
    }
};