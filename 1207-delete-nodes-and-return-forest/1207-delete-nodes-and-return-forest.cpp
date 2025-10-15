/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;

    void fun(TreeNode* root, unordered_set<int>& s, bool is_true) {
        if (!root) return; // ✅ base case

        // agar wo delete karne ko hai
        if (s.find(root->val) != s.end()) {
            fun(root->left, s, true);
            fun(root->right, s, true);
            return; // ✅ important: stop further processing for this node
        }

        // agar wo delete me nahi hai
        // agar wo true hoga matlab uska parent delete hogya hoga isliye push karna hai
        if (is_true) ans.push_back(root);

        // ✅ pehle children ko check karna chahiye (recursion ensures full deletion)
        if (root->left) {
            if (s.find(root->left->val) != s.end()) {
                // agar left delete karne ka ho, uske children ko alag se handle karo
                fun(root->left, s, true);
                root->left = NULL;
            }
        }

        if (root->right) {
            if (s.find(root->right->val) != s.end()) {
                fun(root->right, s, true);
                root->right = NULL;
            }
        }

        // ✅ recurse further normally for non-deleted children
        fun(root->left, s, false);
        fun(root->right, s, false);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ans.clear();
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        fun(root, s, true); 
        return ans;
    }
};
