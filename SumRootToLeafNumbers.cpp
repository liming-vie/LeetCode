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

    void func(TreeNode* root, int num) {
        if(!root)   return;
        
        num=num*10+root->val;
        if(!root->left && !root->right) {
            res+=num;
            return;
        }
        func(root->left, num);
        func(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        func(root, 0);
        return res;
    }
};