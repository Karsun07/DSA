class Solution {
public:
    
   

    
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int ans=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            int diff=v[i+1]-v[i];
            ans=min(ans,diff);
        }
        return ans;
    }
};
