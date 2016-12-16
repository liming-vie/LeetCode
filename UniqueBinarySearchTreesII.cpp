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
    vector<TreeNode*> generateTrees(int n) {
        if(!n)  return vector<TreeNode*>();
        
        vector<vector<vector<TreeNode*>>> dp(n+1,vector<vector<TreeNode*>>(n+1));
        for(int i=1; i<=n; ++i) 
            dp[i][i].push_back(new TreeNode(i));
        for(int l=2; l<=n; ++l) {
            int ui=n-l+1;
            for(int i=1; i<=ui; ++i) {
                int j=i+l-1;
                for(auto t=dp[i][j-1].begin(); t!=dp[i][j-1].end(); ++t) {
                    auto node=new TreeNode(j);
                    node->left=*t;
                    dp[i][j].push_back(node);
                }
                for(auto t=dp[i+1][j].begin(); t!=dp[i+1][j].end(); ++t) {
                    auto node=new TreeNode(i);
                    node->right=*t;
                    dp[i][j].push_back(node);
                }
                for(int k=i+1; k<j; ++k) {
                    for(auto vl=dp[i][k-1].begin(); vl!=dp[i][k-1].end(); ++vl) 
                        for(auto vr=dp[k+1][j].begin(); vr!=dp[k+1][j].end(); ++vr) {
                            auto node=new TreeNode(k);   
                            node->left=*vl;
                            node->right=*vr;
                            dp[i][j].push_back(node);
                        }
                }
            }
        }
        return dp[1][n];
    }
};