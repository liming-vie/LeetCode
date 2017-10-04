/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void pushLeft(TreeNode* root, stringstream* ss, stack<TreeNode*>*st) {
        while (root) {
            (*ss) << ' ' << root->val;
            st->push(root);
            root=root->left;
        }
        (*ss) << " n";
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)  return "";
        
        stack<TreeNode*> st;
        stringstream ss;
        
        pushLeft(root, &ss, &st);
        
        while(!st.empty()) {
            TreeNode* cur=st.top();
            st.pop();
            pushLeft(cur->right, &ss, &st);
        }
        
        cout << ss.str();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len=data.length();
        TreeNode *head = new TreeNode(0), *cur;
        stack<TreeNode*> st;
        st.push(head);
        bool left = true;
        for (int i=1; i<len; ++i) {
            if (data[i] == 'n') {
                if (!left) {
                    cur = st.top();
                    st.pop();
                    while (cur == st.top()->right) {
                        cur = st.top(); 
                        st.pop();
                    }
                }
                left = false;
                ++i;
                continue;
            }
            int vi=data.find(' ', i);
            const string &tmp = data.substr(i, (vi==-1?len:vi) - i);
            cur = new TreeNode(atoi(tmp.c_str()));
            if (left)   st.top()->left = cur;
            else {
                st.top()->right = cur;
                left = true;
            }
            st.push(cur);
            i += tmp.length();
        }
        return head->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));