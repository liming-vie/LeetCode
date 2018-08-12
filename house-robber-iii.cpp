tion for a binary tree node.
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
        
        auto left = func(root->left);
        auto right = func(root->right);
        return make_pair(root->val + left.second + right.second,
                         max(left.first, left.second) + max(right.first, right.second));
    }
    
    int rob(TreeNode* root) {
        auto ret = func(root);
        return max(ret.first, ret.second);
    }
};
