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
    vector<vector<int>> res;
    vector<int> cur;
    
    void func(TreeNode* root, int sum) {
        if(!root)   return;
        sum-=root->val;
        cur.push_back(root->val);
        if(!root->left && !root->right) {
            if(!sum)    res.push_back(cur);
        } else {
            func(root->left, sum);
            func(root->right, sum);   
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        func(root, sum);
        return res;
    }
};