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
    int n;
    int maxi(vector<int>& preorder, int x, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            if (preorder[i] > x) return i;
        }
        return end + 1;  
    }

    TreeNode* fun(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[start]);
        int idx = maxi(preorder, preorder[start], start, end);

        root->left = fun(preorder, start + 1, idx - 1);
        root->right = fun(preorder, idx, end);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        return fun(preorder, 0, n - 1);
    }
};
