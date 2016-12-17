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
    struct Node {
        TreeNode* node;
        bool flag;
    };
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<Node> st;
        TreeNode* move=root;
        while(!st.empty() || move) {
            if (move) {
                st.push(Node{move, false});
                move=move->left;
            } else {
                auto t=st.top();
                st.pop();
                move=t.node;
                if(t.flag || move->right==NULL) {
                    res.push_back(move->val);
                    move=NULL;
                }
                else {
                    st.push(Node{move, true});
                    move=move->right;
                }
            }
        }
        return res;
    }
};