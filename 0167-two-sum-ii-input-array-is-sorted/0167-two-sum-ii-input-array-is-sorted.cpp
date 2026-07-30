class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int t=target-nums[i];

            if(mp.count(t)){
                return {mp[t]+1,i+1};
            }

            mp[nums[i]]=i;


        }
        return {};

    }
};