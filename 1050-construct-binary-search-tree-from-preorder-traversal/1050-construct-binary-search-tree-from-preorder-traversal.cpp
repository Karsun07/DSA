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
    TreeNode* bst(vector<int>& arr, int& i, int lower, int upper) {
        if (i == arr.size() || arr[i] < lower || arr[i] > upper) {
            return NULL;
        }

        
        TreeNode* root = new TreeNode(arr[i++]);

        root->left = bst(arr, i, lower, root->val);
        root->right = bst(arr, i, root->val, upper);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder, i, INT_MIN, INT_MAX);
    }
};
