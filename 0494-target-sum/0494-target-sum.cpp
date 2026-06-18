class Solution {
public:
    int n;
    int tar;
    int count=0;
    void fun(int i,int total,vector<int>&nums){
        if(i==n){
            if(total==tar) count++;
            return;
        }
        fun(i+1,total+nums[i],nums);
        fun(i+1,total-nums[i],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        tar=target;
        fun(0,0,nums);
        return count;
    }
};