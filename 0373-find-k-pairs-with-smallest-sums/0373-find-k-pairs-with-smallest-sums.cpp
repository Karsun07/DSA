class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>p;
        for(int i=0;i<nums1.size();i++){//sum,num[i],num[j]
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                if(p.size()<k) p.push({sum,{nums1[i],nums2[j]}});
                else{
                    if(sum<p.top().first){
                        p.pop();
                        p.push({sum,{nums1[i],nums2[j]}});
                    }
                    else break;
                }
            }
        }
        while(!p.empty()){
            ans.push_back({p.top().second.first,p.top().second.second});
            p.pop();
        }
        return ans;
        
    }
};