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
    TreeNode* func(TreeNode* cur, TreeNode* parent) {
      if (!cur)  return NULL;
      TreeNode* ret = func(cur->left, cur);

      if (parent) {
        cur->left = parent->right;
        cur->right = parent;
      } else {
        cur->left = cur->right = NULL;
      }
      
      return ret ? ret : cur;
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return func(root, NULL);
    }
};