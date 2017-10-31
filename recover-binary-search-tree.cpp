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
    TreeNode *last=NULL, *first=NULL, *second=NULL;
    
    void visit(TreeNode *cur) {
        if (last && last->val > cur->val) {
            if (!first) first=last;
            second = cur;
        }
        last=cur;
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *pre=NULL, *cur=root;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right && pre->right!=cur)   pre=pre->right;
                
                if (pre->right) {
                    visit(cur);
                    cur=cur->right;
                    pre->right=NULL;
                } else {
                    pre->right=cur;
                    cur=cur->left;
                }
            } else {
                visit(cur);
                cur=cur->right;
            }
        }
        if (first && second)    swap(first->val, second->val);
    }
};