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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        q2.push(root);
        while(!q1.empty() && !q2.empty()) {
            auto a=q1.front(); q1.pop(); 
            auto b=q2.front(); q2.pop();
            if(!a && !b)    continue;
            if(!a || !b || a->val != b->val) return false;
            q1.push(a->left);
            q2.push(b->right);
            q1.push(a->right);
            q2.push(b->left);
        }
        return q1.empty()==q2.empty();
    }
};