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
    vector<TreeNode*> nodes;
    vector<int> nums;
    
    void Inorder(TreeNode* root) {
        if(!root)   return;
        Inorder(root->left);
        nodes.push_back(root);
        nums.push_back(root->val);
        Inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        Inorder(root);
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i)
            nodes[i]->val=nums[i];
    }
};