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
    void fun(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>>& ans) {
        if (!root) return;

        temp.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0) {
            ans.push_back(temp);
            return;
        }
        fun(root->left, targetSum, temp, ans);
        fun(root->right, targetSum,temp, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>temp;
        fun(root, targetSum,temp, ans);
        return ans;
    }
};
