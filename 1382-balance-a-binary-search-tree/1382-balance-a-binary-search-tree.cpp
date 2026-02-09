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
    void inorder(TreeNode* root,vector<int>&arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* merge(int start,int end,vector<int>&arr){
        if(start>end) return NULL; 
        int mid=start+(end-start)/2;
        TreeNode* head=new TreeNode(arr[mid]);
        head->left=merge(start,mid-1,arr);
        head->right=merge(mid+1,end,arr);
        return head;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int n=arr.size();
        return merge(0,n-1,arr);
        
    }
};