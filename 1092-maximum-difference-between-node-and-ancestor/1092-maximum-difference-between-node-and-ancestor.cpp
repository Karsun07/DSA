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
    void fun(TreeNode* root,vector<int>temp,int &ans){
        if(!root) return ;
        for(int i=0;i<temp.size();i++){
            ans=max(ans,abs(temp[i]-root->val));
        }
        temp.push_back(root->val);
        
        fun(root->left,temp,ans);
        fun(root->right,temp,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int>temp;
        int ans=0;
        fun(root,temp,ans);
        return ans;
        
    }
};