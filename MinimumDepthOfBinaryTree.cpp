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
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        int res=0;
        if(root->left) 
            res=minDepth(root->left);
        if(root->right) {
            int tmp=minDepth(root->right);
            if(res==0 || res>tmp)   res=tmp;
        }
        return res+1;
    }
};