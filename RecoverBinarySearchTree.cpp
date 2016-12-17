/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// morris traversal; refer to http://www.cnblogs.com/grandyang/p/4298069.html
 
 #define CHECK()    \
    if(last && last->val > cur->val) {  \
        if(!first)  first=last;         \
        second=cur;                     \
    }                                   \
    last=cur;
 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre, *cur=root, *first=NULL, *second=NULL, *last=NULL;
        while(cur) {
            if(cur->left) {
                pre=cur->left;
                while(pre->right && pre->right != cur) pre=pre->right;
                if(pre->right) {
                    CHECK();
                    cur=cur->right;
                    pre->right=NULL;
                } else {
                    pre->right=cur;
                    cur=cur->left;
                }
            } else {
                CHECK();
                cur=cur->right;
            }
        }
        if(first && second) swap(first->val, second->val);
    }
};