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
    bool valid(TreeNode* root, long long max, long long min) {
        if(!root)   return true;
        if(root->val >= max || root->val <= min)  return false;
        return valid(root->left, root->val, min) && valid(root->right, max, root->val);
    }

    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))    return true;
        long long max=0x7fffffff, min=-max-1;
        
        return valid(root, ++max, --min);
    }
};