/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define MAX(a,b) (a>b?a:b)
 
class Solution {
public:
    int res=1<<31;
    
    int func(TreeNode* root) {
        if(!root)   return 0;
        int a=func(root->left), b=func(root->right);
        int max=a+b+root->val;
        int tmp=MAX(a,b)+root->val;
        tmp=MAX(tmp, root->val);
        max=MAX(max, tmp);
        res=MAX(max, res);
        return tmp;
    }
    
    int maxPathSum(TreeNode* root) {
        func(root);
        return res;
    }
};