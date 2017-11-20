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
    pair<int, double> func(TreeNode* root, double target) {
        double diff = fabs(target-root->val);
        if (root->val==target || (!root->left && !root->right) ||
            (!root->left && root->val>target) || (!root->right && root->val<target))
            return make_pair(root->val, diff);
        
        const auto& ret = func(target<root->val?root->left:root->right, target);
        return diff < ret.second ? make_pair(root->val, diff) : ret;
    }
    
    int closestValue(TreeNode* root, double target) {
        return func(root, target).first;
    }
};