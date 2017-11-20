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
    
    int find(TreeNode* root) {
        if (!root)  return 0;
        int h = max(find(root->left), find(root->right));
        
        if (res.size()==h) {
            res.push_back(vector<int>{root->val});
        } else {
            res[h].push_back(root->val);
        }
        
        return h+1;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return res;
        
        find(root);
        return res;
    }
};