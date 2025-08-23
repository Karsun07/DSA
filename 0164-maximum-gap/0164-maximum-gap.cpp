class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int maxdiff=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            maxdiff=max(maxdiff,nums[i+1]-nums[i]);
        }
        return maxdiff;
    }
};