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
    int steps=0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l_req=dfs(root->left),r_req=dfs(root->right);
        steps+=abs(l_req)+abs(r_req);
        return (root->val-1)+l_req+r_req;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
        
    }
};