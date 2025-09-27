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
    int find(int x,vector<int>in){
        for(int i=0;i<in.size();i++){
            if(in[i]==x) return i;
        }
        return -1;
    }
    TreeNode* fun(vector<int>&pre,vector<int>&in,int start,int end){
        if(start>end) return NULL;
        TreeNode* root=new TreeNode(pre[i]);
        
        int idx=find(pre[i],in);
        i++;
        if(idx==-1) return NULL;
        root->left=fun(pre,in,start,idx-1);
        root->right=fun(pre,in,idx+1,end);
        return root;

       
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        i=0;
        int n=preorder.size();
        return fun(preorder,inorder,0,n-1);
        
        
    }
};