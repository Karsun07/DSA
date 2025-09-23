class Solution {
public:
    void fun(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;

        if (!path.empty()) path += "->";
        path += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        fun(root->left, path, ans);
        fun(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        fun(root, "", ans);
        return ans;
    }
};
