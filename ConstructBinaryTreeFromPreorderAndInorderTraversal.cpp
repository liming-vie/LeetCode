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
    TreeNode* build(vector<int>&preorder, int& pl, vector<int>&inorder, int il, int ir) {
        if(il>ir)  return NULL;
        auto root=new TreeNode(preorder[pl]);
        int t=il;
        while(t<=ir) {
            if(inorder[t]==preorder[pl]) 
                break;
            ++t;
        }
        root->left=build(preorder, ++pl, inorder, il, t-1);
        root->right=build(preorder, pl, inorder, t+1, ir);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int vi=0;
        return build(preorder, vi, inorder, 0, inorder.size()-1);
    }
};