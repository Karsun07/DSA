class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int shift=(i+nums[i])%n;
            if(shift<0) shift+=n;
            result[i]=nums[shift];
        }
        return result;

    }
};