/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MP(a,b) make_pair((a),(b))
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(MP(root, root->val));
        int res=0;
        while(!q.empty()) {
            auto t=q.front(); q.pop();
            int num=t.second;
            if(!t.first->left && !t.first->right)
                res+=num;
            else {
                num*=10;
                if(t.first->left)   q.push(MP(t.first->left, num+t.first->left->val));
                if(t.first->right)   q.push(MP(t.first->right, num+t.first->right->val));
            }
        }
        return res;
    }
};