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
    int max=0, min=0;
    void computeRange(TreeNode*root, int val) {
        if (!root)  return;
        max = max > val ? max : val;
        min = min < val ? min : val;
        computeRange(root->left, val-1);
        computeRange(root->right, val+1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)  return vector<vector<int>>();
        
        computeRange(root, 0);
        vector<vector<int>> res(max-min+1);
        
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(-min, root));
        
        while(!q.empty()) {
            const auto &top = q.front();
            q.pop();
            
            res[top.first].push_back(top.second->val);
            
            if (top.second->left) q.push(make_pair(top.first-1, top.second->left));
            if (top.second->right) q.push(make_pair(top.first+1, top.second->right));
        }
        
        return res;
    }
};