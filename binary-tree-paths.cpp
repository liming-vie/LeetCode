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
    vector<string> res;
    vector<int> cur;
    
    void traversal(TreeNode* root) {
        if (!root) {
            return;
        }
        
        cur.push_back(root->val);
        
        if (!root->left && !root->right) {
            stringstream ss;
            ss << cur[0];
            for (int i=1; i<cur.size(); ++i) {
                ss << "->" << cur[i];
            }
            res.push_back(ss.str());
        }
        
        traversal(root->left);
        traversal(root->right);
        
        cur.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        traversal(root);
        
        return res;
    }
};