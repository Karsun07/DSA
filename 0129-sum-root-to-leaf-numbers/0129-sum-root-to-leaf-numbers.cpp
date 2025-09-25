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
    void fun(TreeNode* root,string temp,vector<string>&ans){
        if(!root) return;
        string s=to_string(root->val);
        temp+=s;
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        fun(root->left,temp,ans);
        fun(root->right,temp,ans);

    }
    int sumNumbers(TreeNode* root) {
        vector<string>ans;
        string temp="";
        fun(root,temp,ans);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            int num=stoi(ans[i]);
            sum+=num;
        }
        return sum;
    }
};