/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define ABS(a) ((a)<0?0-(a):(a))
 
class Solution {
public:
    bool flag=false;
    int traversal(TreeNode* root) {
        if(!root || flag)   return 0;
        int a=traversal(root->left), b=traversal(root->right);
        if(ABS(a-b)>1) {
            flag=true;
            return 0;
        }
        return 1+(a>b?a:b);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        traversal(root);
        return !flag;
    }
};