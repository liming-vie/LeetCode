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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)  return NULL;
        if (p->right) {
            p = p->right;
            while(p->left) {
                p=p->left;
            }
            return p;
        }
        
        TreeNode* move = root;
        stack<TreeNode*> st;
        while(move) {
            if (move->val < p->val) {
                move = move->right;
            }
            else if (move-> val > p->val) {
                st.push(move);
                move = move->left;
            } else {
                if (st.empty()) return NULL;
                return st.top();
            }
        }
        
        return NULL;
    }
};