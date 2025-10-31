class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==1){
                ans.push_back(nums[i]);
                continue;
            } 
            mp[nums[i]]++;
            
        }
        return ans;
    }
};