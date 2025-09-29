class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,sum=0;
        int ans=INT_MAX;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;

            }
            r++;
        }
        return (l==0 && r==n)?0:ans;


        
    }
};