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
    int widthOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {

            int n = q.size();

            unsigned long long start = q.front().second;
            unsigned long long end = start;

            while (n--) {

                auto [node, idx] = q.front();
                q.pop();

                idx -= start;
                end = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});

                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            ans = max(ans, end + 1);
        }

        return ans;
    }
};