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
    TreeNode* fun(vector<int>&nums,int start,int end){
        if(end<start) return NULL;
        int n=nums.size();
        int max_idx=-1,maxi=INT_MIN;
        for(int i=start;i<=end;i++){
            if(maxi<nums[i]){
                max_idx=i;
                maxi=nums[i];
            }
        }
        TreeNode* root=new TreeNode(nums[max_idx]);
        root->left=fun(nums,start,max_idx-1);
        root->right=fun(nums,max_idx+1,end);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n=nums.size();
        return fun(nums,0,n-1);
    }
};