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
    pair<int, int> func(TreeNode* root) {
        if (!root)  return make_pair(0, 0);
        
        const auto &left=func(root->left);
        const auto &right=func(root->right);
        
        int nor = max(left.first, left.second) + max(right.first, right.second);
        int rb = left.second + right.second + root->val;
        
        return make_pair(rb, nor);
    }
    
    int rob(TreeNode* root) {
        const auto& res = func(root);
        return max(res.first, res.second);
    }
};