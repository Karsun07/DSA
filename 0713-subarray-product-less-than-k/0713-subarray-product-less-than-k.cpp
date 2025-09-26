class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,count=0;
        int prod=1;
        int n=nums.size();
        while(r<n){
            prod*=nums[r];
            while(prod>=k && l<=r){
                prod/=nums[l];
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;

        
    }
};