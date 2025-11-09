class Solution {
public:
    int minimumDistance(vector<int>& nums) {
       unordered_map<int,vector<int>>mp;
       int n=nums.size();
       int ans=INT_MAX;
       if(n<3) return -1;
       for(int i=0;i<n;i++){
          mp[nums[i]].push_back(i);
       }
       for(auto it:mp){
          auto &arr=it.second;
          int m=arr.size();
          if(m>=3){
            for(int i=0;i<m-2;i++){
                int dist=arr[i+2]-arr[i];
                ans=min(ans,dist);
            }
          }
       }
       return ans==INT_MAX?-1:2*ans;

        
        
    }
};