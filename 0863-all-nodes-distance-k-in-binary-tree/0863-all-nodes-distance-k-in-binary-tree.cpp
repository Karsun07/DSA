/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root,unordered_map<int,vector<int>>&adj){
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            buildGraph(root->left,adj);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            buildGraph(root->right,adj);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>adj;

        buildGraph(root,adj);

        queue<pair<int,int>>q;
        unordered_set<int>visited;

        q.push({target->val,0});
        visited.insert(target->val);
        vector<int>ans;
        ans.clear();
        while(!q.empty()){
            auto [node,dist]=q.front();
            q.pop();
            if(dist==k){
                ans.push_back(node);
                continue;
            }

            for(auto nb:adj[node]){
                if(!visited.count(nb)){
                    visited.insert(nb);
                    q.push({nb,dist+1});
                }                
            }
        }
        return ans;


        
    }
};