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
    bool check(TreeNode* root, long long min, long long max) {
        if (!root)  return true;
        if (root->val <= min || root->val >= max) return false;
        
        return check(root->left, min, root->val) && check(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        long long min = 1<<31;
        long long max = ~(1<<31);
        return check(root, min - 1, max + 1);
    }
};