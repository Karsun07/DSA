class Solution {
public:
    int ans=INT_MAX;
    void in(TreeNode* root,int &prev){
        if(!root) return;
        in(root->left,prev);
        if(prev!=-1) ans=min(ans,root->val-prev);
        prev=root->val;
        in(root->right,prev);
    }
    int minDiffInBST(TreeNode* root) {
       int prev=-1;
       in(root,prev);
       return ans;

    }
};
