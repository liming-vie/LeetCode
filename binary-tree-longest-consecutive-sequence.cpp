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
    
    pair<int, int> func(TreeNode* root) {
        if (!root)  return make_pair(0, 0);
        
        const auto& left = func(root->left);
        const auto& right = func(root->right);
        
        int len=0;
        if (left.first && left.second==root->val+1) {
            len=left.first;
        }
        if (right.first && right.second==root->val+1) {
            len=max(len, right.first);
        }
        ++len;
        res = max(len, res);
        return make_pair(len, root->val);
    }
    
    int longestConsecutive(TreeNode* root) {
        func(root);
        return res;
    }
};