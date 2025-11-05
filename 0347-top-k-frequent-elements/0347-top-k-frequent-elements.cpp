class Solution {
public:
    vector<int>ans;
    void fun(unordered_map<int,int>&m,int k){
        priority_queue<pair<int,int>>p;//freq,num
        for(auto& it:m){
            p.push({it.second,it.first});
        }
        while(!p.empty()&& k--){
            auto x=p.top();
            p.pop();
            ans.push_back(x.second);
        }

    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;//num,freq
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        fun(m,k);
        return ans;


    }
};