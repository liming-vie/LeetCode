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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        vector<TreeNode*> cur, next;
        vector<int> tmp;
        cur.push_back(root);
        bool flag=false;
        while(cur.size()) {
            for(int i=cur.size()-1; i>=0; --i) {
                tmp.push_back(cur[i]->val);
                if(flag) {
                    if(cur[i]->right)    next.push_back(cur[i]->right);
                    if(cur[i]->left)    next.push_back(cur[i]->left);
                }
                else {
                    if(cur[i]->left)    next.push_back(cur[i]->left);
                    if(cur[i]->right)    next.push_back(cur[i]->right);
                }
            }
            res.push_back(tmp);
            tmp.clear();
            flag=!flag;
            cur.clear();
            swap(next, cur);
        }
        return res;
    }
};