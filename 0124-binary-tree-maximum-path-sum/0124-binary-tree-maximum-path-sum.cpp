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
    int maxi = INT_MIN;

    int fun(TreeNode* root) {
        if (!root)
            return 0;

        int p1 = max(0, fun(root->left));
        int p2 = max(0, fun(root->right));

        maxi = max(maxi, p1 + p2 + root->val);

        return root->val + max(p1, p2);
    }

    int maxPathSum(TreeNode* root) {
        fun(root);
        return maxi;
    }
};