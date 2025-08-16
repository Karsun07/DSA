class Solution {
public:
void perm(vector<int> nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& visited) {
    if (temp.size() == nums.size()) { 
        ans.push_back(temp);
        return;
    }
    
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {  
            visited[i] = true; 
            temp.push_back(nums[i]);
            perm(nums, ans, temp, visited);
            temp.pop_back(); 
            visited[i] = false; 
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    
    perm(nums, ans, temp, visited);
    return ans;
    }
};