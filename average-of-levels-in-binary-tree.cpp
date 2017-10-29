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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root)  return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int count=0;
        long long sum=0.;
        while (!q.empty()) {
            const auto& move = q.front();
            
            if (move) {
                ++count;
                sum+=move->val;
                if (move->left) q.push(move->left);
                if (move->right) q.push(move->right);
            } else {
                res.push_back((double)sum/count);
                sum = 0.;
                count = 0;
                if (q.size()>1)   q.push(NULL);
            }
            
            q.pop();
        }
        
        return res;
    }
};