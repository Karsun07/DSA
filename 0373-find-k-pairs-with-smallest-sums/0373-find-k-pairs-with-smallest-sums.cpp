class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int num:nums1){
            p.push({num+nums2[0],0});
        }
        int n=nums2.size();
        while(!p.empty()&&k--){
            auto x=p.top();
            int sum=x.first;
            int pos2=x.second;
            p.pop();
            ans.push_back({sum-nums2[pos2],nums2[pos2]});
            if(pos2<n-1){
                p.push({sum+nums2[pos2+1]-nums2[pos2],pos2+1});
            }

        }
        return ans;
    }
};