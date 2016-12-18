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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        
        vector<int> cur;
        queue<TreeNode*> q;
        q.push(root); q.push(NULL);
        while(!q.empty()) {
            auto t=q.front();
            q.pop();
            if(t) {
                cur.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right)q.push(t->right);
            } else {
                res.push_back(cur);
                if(q.empty())   break;
                q.push(NULL);
                cur.clear();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};