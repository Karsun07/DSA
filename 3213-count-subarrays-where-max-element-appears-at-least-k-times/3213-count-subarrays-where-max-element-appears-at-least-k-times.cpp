class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi=INT_MIN;
        long long n=nums.size();
      
        for (int i=0;i<n;i++) {
            maxi=max(maxi,(long long)nums[i]);
        }
        
        long long l =0,r=0,freq=0;
        long long count=0;
        
        while(r<n){
            if(nums[r]==maxi) freq++;
            
            while(l<=r && freq==k) {
                count+=(n-r);
                if(nums[l]==maxi) freq--;
                l++;
            }
            
            r++;
        }
        
        return count;
    }
};
