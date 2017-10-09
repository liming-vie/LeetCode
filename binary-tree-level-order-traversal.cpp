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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur;
        while (!q.empty()) {
            auto *tmp = q.front();
            q.pop();
            
            if (tmp) {
                cur.push_back(tmp->val);
                if (tmp->left)  q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            } else {
                res.push_back(cur);
                if (q.empty())  break;
                cur.clear();
                q.push(NULL);
            }
        }
        return res;
    }
};