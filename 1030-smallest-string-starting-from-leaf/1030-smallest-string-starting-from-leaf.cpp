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
    void dfs(TreeNode* root, string temp, string &smallest) {
        if (!root) return;

        temp+='a'+root->val;
       

        if(!root->left && !root->right){
            reverse(temp.begin(),temp.end());
            if(smallest=="" || temp<smallest){
                smallest=temp;
            }
            reverse(temp.begin(),temp.end());
        }
        

        dfs(root->left, temp, smallest);
        dfs(root->right, temp, smallest);
    }

    string smallestFromLeaf(TreeNode* root) {
        string smallest = "";
        string temp="";
        dfs(root, "", smallest);
        return smallest;
    }
};
