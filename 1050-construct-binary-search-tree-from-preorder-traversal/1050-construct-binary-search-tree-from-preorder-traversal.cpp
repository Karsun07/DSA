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
    int i;
    TreeNode* fun(vector<int>&arr,int lower,int upper){
        if(i==arr.size()||arr[i]<lower || arr[i]>upper) return NULL;
        TreeNode* root=new TreeNode(arr[i]);
        i++;
        root->left=fun(arr,lower,root->val);
        root->right=fun(arr,root->val,upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i=0;
        return fun(preorder,INT_MIN,INT_MAX);

        
    }
};
