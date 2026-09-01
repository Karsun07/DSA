class Solution:
    def fun(self,i,nums,dp):
        if i>=len(nums):
            return 0
        if dp[i]!=-1:
            return dp[i]

        take=nums[i]+self.fun(i+2,nums,dp)
        nottake=self.fun(i+1,nums,dp)
        dp[i]=max(take,nottake)
        return dp[i]
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[-1]*n
        return self.fun(0,nums,dp)
        