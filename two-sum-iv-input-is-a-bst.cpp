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
    bool find(TreeNode* first, TreeNode *root, int k) {
        if (!first) return false;
        int target=k-first->val;
        TreeNode*move=root;
        while (move) {
            if (move->val==target) {
                if (move!=first)    return true;
                break;
            } else if (move->val>target)    move=move->left;
            else    move=move->right;
        }
        
        return find(first->left, root, k) || find(first->right, root, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return find(root, root, k);
    }
};