class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProd=nums[0];
        int currmax=nums[0];
        int currmin=nums[0];

        for(int i=1;i<n;i++){

            if(nums[i]<0) swap(currmax,currmin);

            currmax=max(nums[i],currmax*nums[i]);
            currmin=min(nums[i],currmin*nums[i]);

            maxProd=max(maxProd,currmax);
        }
        return maxProd;
    }
};