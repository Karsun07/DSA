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
    void fun(TreeNode* root, vector<int> temp, int target, int &count) {
        if (!root) return;   
        temp.push_back(root->val);
        long long sum = 0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            sum += temp[i];
            if (sum == target) count++;
        }

        fun(root->left, temp, target, count);
        fun(root->right, temp, target, count);
        
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int count = 0;
        fun(root, temp, targetSum, count);
        return count;
    }
};
