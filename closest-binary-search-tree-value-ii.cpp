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
    void inorder(TreeNode* root, double target, bool reverse, stack<int>& st) {
        if (!root) return;
        
        inorder(reverse?root->right:root->left, target, reverse, st);
        if ((reverse && root->val<=target) || (!reverse && root->val>target))
            return;
        st.push(root->val);
        inorder(reverse?root->left:root->right, target, reverse, st);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> smaller, larger;
        inorder(root, target, false, smaller);
        inorder(root, target, true, larger);
        
        vector<int> res;
        while (k--) {
            if (smaller.empty() || (!larger.empty() && target-smaller.top()>larger.top()-target)) {
                res.push_back(larger.top());
                larger.pop();
            } else {
                res.push_back(smaller.top());
                smaller.pop();
            }
        }
        return res;
    }
};