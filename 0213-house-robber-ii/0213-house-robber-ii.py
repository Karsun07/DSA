class Solution:
    def helper(self, i, nums, dp):
        if i >= len(nums):
            return 0

        if dp[i] != -1:
            return dp[i]

        take = nums[i] + self.helper(i + 2, nums, dp)
        notTake = self.helper(i + 1, nums, dp)

        dp[i] = max(take, notTake)

        return dp[i]

    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        dp1 = [-1] * (n - 1)
        case1 = self.helper(0, nums[:n-1], dp1)

        dp2 = [-1] * (n - 1)
        case2 = self.helper(0, nums[1:], dp2)

        return max(case1, case2)