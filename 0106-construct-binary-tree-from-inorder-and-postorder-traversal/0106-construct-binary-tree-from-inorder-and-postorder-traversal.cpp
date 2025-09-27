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
    TreeNode* fun(vector<int>&post,vector<int>&in,int start,int end){
        if(start>end) return NULL;
        TreeNode* root=new TreeNode(post[i]);
        
        int idx=find(post[i],in);
        i--;
        if(idx==-1) return NULL;
        root->right=fun(post,in,idx+1,end);
        root->left=fun(post,in,start,idx-1);
       
        return root;

       
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=postorder.size();
        i=n-1;
        return fun(postorder,inorder,0,n-1);
        
    }
};