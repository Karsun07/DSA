class Solution {
public:
    
    int mindiff(const vector<int>& v, int index) {
        if (index == v.size() - 1) return INT_MAX; 

        int diff = v[index + 1] - v[index];
        return min(diff, mindiff(v, index + 1));
    }

    
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return mindiff(v, 0);
    }
};
