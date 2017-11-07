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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        queue<TreeNode*> q;
        q.push(NULL);   q.push(root);
        while (true) {
            auto front = q.front(); q.pop();
            if (!front) {
                if (q.empty() || q.front()==NULL) break;
                res.push_back(q.front()->val);
                q.push(NULL);
                continue;
            }
            if (front->right)    q.push(front->right);
            if (front->left)    q.push(front->left);
        }
        
        return res;
    }
};