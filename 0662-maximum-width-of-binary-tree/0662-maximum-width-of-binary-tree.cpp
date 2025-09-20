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
    unordered_map<TreeNode*, unsigned long long> m;

    void fun(TreeNode* root, unsigned long long i) {
        if (!root) return;
        m[root] = i;
        if (root->left) fun(root->left, 2 * i + 1);
        if (root->right) fun(root->right, 2 * i + 2);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        fun(root, 0);
        queue<TreeNode*> q;
        q.push(root);
        
        long long ans = 1;  // use long long to avoid type mismatch
        while (!q.empty()) {
            int n = q.size();
            unsigned long long x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (i == 0) x = m[temp];
                if (i == n - 1) y = m[temp];
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans = max(ans, (long long)(y - x + 1));
        }
        return (int)ans;
    }
};
