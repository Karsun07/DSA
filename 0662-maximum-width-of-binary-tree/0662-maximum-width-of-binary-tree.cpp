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

            int sz = q.size();

            // First position of this level
            unsigned long long first = q.front().second;

            unsigned long long firstPos = 0;
            unsigned long long lastPos = 0;

            while (sz--) {

                TreeNode* node = q.front().first;
                unsigned long long pos = q.front().second;

                q.pop();

                // Normalize position
                pos -= first;

                if (sz == 0)
                    lastPos = pos;

                if (node->left)
                    q.push({node->left, 2 * pos});

                if (node->right)
                    q.push({node->right, 2 * pos + 1});
            }

            ans = max(ans, lastPos + 1);
        }

        return (int)ans;
    }
};