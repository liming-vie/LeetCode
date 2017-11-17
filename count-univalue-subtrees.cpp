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
    int res=0;
    
    pair<int, bool> valid(TreeNode* root, int val) {
        if (!root)  return make_pair(val, true);
        
        const auto &left = valid(root->left, root->val);
        const auto &right = valid(root->right, root->val);
        
        if (left.second && left.first==root->val && right.second && right.first==root->val) {
            ++res;
            return make_pair(root->val, true);
        }
        
        return make_pair(0, false);
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        valid(root, 0);
        return res;
    }
};