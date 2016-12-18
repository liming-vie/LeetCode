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
    TreeNode* build(vector<int>&inorder, int il, int ir, vector<int>&postorder, int &pr) {
        if(il>ir)   return NULL;
        auto root=new TreeNode(postorder[pr]);
        int t=il;
        while(t<=ir) {
            if(inorder[t]==root->val) 
                break;
            ++t;
        }
        root->right=build(inorder,t+1, ir, postorder, --pr);
        root->left=build(inorder, il, t-1, postorder, pr);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pr=postorder.size()-1;
        return build(inorder, 0, inorder.size()-1, postorder, pr);
    }
};