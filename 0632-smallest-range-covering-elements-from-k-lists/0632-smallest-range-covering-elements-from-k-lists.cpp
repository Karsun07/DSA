class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
      
        priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>>p;
        int maxi=INT_MIN;
        
        for(int i=0;i<k;i++){
            p.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        int mini=p.top().first;
        int r=maxi-mini;
        vector<int>ans(2);
        ans={mini,maxi};
        
        pair<int,pair<int,int>>ele;
        while(p.size()==k){
            ele=p.top();
            p.pop();
            int i=ele.second.first;
            int j=ele.second.second;
            if(j+1<nums[i].size()){
                p.push({nums[i][j+1],{i,j+1}});
                mini=p.top().first;
                maxi=max(maxi,nums[i][j+1]);
                if(maxi-mini <r){
                    r=maxi-mini;
                    ans[0]=mini;
                    ans[1]=maxi;
                }

                
            }
        }
        return ans;
    }
};
